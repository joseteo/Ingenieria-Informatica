require_relative 'dado'
require_relative 'civitas_juego'
require_relative 'titulo_propiedad'
require_relative 'diario'

module Civitas

class Jugador
  
    @@Saldoinicial = 7500;
    @@casasMax = 4;
    @@CasasPorHotel = 4
    @@hotelesMax = 4
    @@PasoPorSalida = 1000
    @@precioLibertad = 200
  
  def initialize(nomb)  
    @encarcelado = false
    @nombre = nomb
    @numCasillaActual = 0
    @puedeComprar = true
    @saldo = @@Saldoinicial
    @salvoconducto = nil
    @propiedades = Array.new
  end
  
  def cancelar_hipoteca(ip)
    resultado=false
    if is_encarcelado==false
      if existe_la_propiedad(ip)
        propi = @propiedades.at(ip)
        cantid = propi.getimportecancelarhipoteca
        puedoGastar = puedoGastar(cantid)
        if puedoGastar==true
          resultado = propi.cancelar_hipoteca(self)
          if resultado == true
            Diario.instance.ocurre_evento("El jugador #{@nombre} cancela la hipoteca de la propiedad #{ip}")
          end
        end
      end
    end
    return resultado
  end
  
  def cantidadcasashoteles
    resultado=0
    for i in 0...@propiedades.length
      resultado=resultado + @propiedades.at(i).cantidadcasashoteles
    end
    return resultado
  end
  
  def compareto(otro)
    if self.getsaldo < otro.getsaldo
      resultado=resultado-1
    elsif self.getsaldo > otro.getsaldo
      resultado=1
    else
      resultado=0
    end
    return resultado
  end
  
  def comprar (titulo)
    result=false
    
    if encarcelado
      return result
    end
      
      if puedeComprar
        precio = titulo.preciocompra
        
      
        if puedoGastar(precio)
          result = titulo.comprar(self)
          
          if result
            @propiedades.push(titulo)
            
            Diario.instance.ocurre_evento("El jugador #{@nombre} compra la propiedad #{titulo.tostring()}")
             puedeComprar=false
          end
          
         
        end
      end
    
    return result
  end
  
  def construircasa(ip)
    resultado=false
    puedoEdificarCasa = false
    if is_encarcelado==false
      existe = existe_la_propiedad(ip)
      if existe
        propiedad = @propiedades.at(ip)
        puedoEdificarCasa = puedo_edificar_casa(propiedad)
        if puedoEdificarCasa==true
          resultado = propiedad.construircasa(self)
          if resultado
            Diario.instance.ocurre_evento("El jugador #{@nombre} construye casa en la propiedad #{ip}")
          end
        end
      end
    end
    return resultado
  end
  
  def construirhotel(ip)
    resultado=false
    if is_encarcelado==false
      if existe_la_propiedad(ip)
        propiedad = @propiedades.at(ip)
        puedoEdificarHotel = puedo_edificar_hotel(propiedad)
        if puedoEdificarHotel==true
          resultado = propiedad.construirhotel(self)
          propiedad.derruircasas(@@CasasPorHotel,self)          
          Diario.instance.ocurre_evento("El jugador #{@nombre} construye hotel en la propiedad #{ip}")
        end
      end
    end
    return resultado
  end
  
  def debe_ser_encarcelado
    encarcel = false
    if(is_encarcelado()==false)
      if(tiene_salvoconducto()==false)
        encarcel = true
      else
        encarcel = false
        perder_salvoconducto
        Diario.instance.ocurre_evento("el jugador #{@nombre} usa el salvoconducto")
      end
    end
    return encarcel
  end
  
  def enbancarrota
    resultado=false
    sal = @saldo
    resultado =true if sal < 0
    return resultado
  end
  
  def encarcelar(numCasillaCarcel)
    if(debe_ser_encarcelado==true)
      mover_a_casilla(numCasillaCarcel)
      @encarcelado = true
      Diario.instance.ocurre_evento("El jugador #{@nombre} ha sido encarcelado")
    end
    return @encarcelado
  end
  
  def existe_la_propiedad(ip)
    resultado=false
    resultado=true if @propiedades.at(ip) != nil
  end
  
  def hipotecar(ip)
    resultado=false
    if is_encarcelado==false
      if existe_la_propiedad(ip)
        propiedad = @propiedades.at(ip)
        resultado = propiedad.hipotecar(self)
      end
    end
    if resultado
      Diario.instance.ocurre_evento("El jugador #{@nombre} hipoteca la pripiedad #{ip}")
    end
    return resultado
  end
  
  def is_encarcelado
    return @encarcelado
  end
  
  def jugador(otro)
    @encarcelado = otro.encarcelado
    @nombre = otro.nombre
    @numCasillaActual = otro.numCasillaActual
    @puedeComprar = otro.puedeComprar
    @saldo = otro.saldo
    @salvoconducto = otro.salvoconducto
    @propiedades = otro.propiedades
  end

  def modificar_saldo(cantidad)
    @saldo = @saldo + cantidad
    Diario.instance.ocurre_evento("Saldo modificado")
    modificado = true
    return modificado
  end
  
  def mover_a_casilla (numCasilla)
    mover = false
    if(is_encarcelado() == false)
      @numCasillaActual = numCasilla
      @puedeComprar = false
      mover = true
      Diario.instance.ocurre_evento("El jugador #{@nombre} ha sido movido a la casilla #{numCasilla}")
    end
    return mover   
  end
  
  def obtener_salvoconducto(s)
    ob_salvo = false
    if(is_encarcelado()==false)
      ob_salvo=true
      @salvoconducto = s
    end
    return ob_salvo
  end

  def paga(cantidad)
      return modificar_saldo(cantidad * -1)
  end
  
  def paga_alquiler(cantidad)
    resultado = false
    if (is_encarcelado()==false)
      resultado = paga(cantidad)
      Diario.instance.ocurre_evento("El jugador #{@nombre} paga #{cantidad} euros por alquiler")
    end
    return resultado
  end
  
  def paga_impuesto(cantidad)
    resultado = false
    if (is_encarcelado==false)
      resultado = paga(cantidad)
      Diario.instance.ocurre_evento("El jugador #{@nombre} paga #{cantidad} euros por impuesto")
    end
    return resultado
  end
  
  def pasa_por_salida
    paso = true
    Diario.instance.ocurre_evento("El jugador #{@nombre} ha pasado por salida")
    modificar_saldo(@@PasoPorSalida)
    return paso      
  end
  
  def perder_salvoconducto
    @salvoconducto.usada
    @salvoconducto = nil 
  end

  def puede_comprar_casilla
    @puedeComprar = true;
    if (is_encarcelado == true)
      @puedeComprar = false;
    end
    return @puedeComprar
  end
  
  def puede_salir_carcel_pagando
    salir = false
    if(@saldo >= @@precioLibertad)
      salir =true
    end
    return salir
  end
  
  def puedo_edificar_casa(propiedad)
    puedo = false
    precio = propiedad.precioedificar
    if puedoGastar(precio) and propiedad.numcasas < @@casasMax
      puedo = true
    end
    return puedo
  end
  
  def puedo_edificar_hotel(propiedad)
    puedo = false
    precio = propiedad.precioedificar
    if puedoGastar(precio)
      if propiedad.numhoteles < @@hotelesMax
        if propiedad.numcasas >= @@CasasPorHotel
          puedo = true
        end
      end
    end
    return puedo
  end
  
  def puedoGastar(precio)
    gastar = false
    if (is_encarcelado()== false and @saldo >=precio)
      gastar= true
    end  
    return gastar
  end
  
  def recibe(cantidad)
    resultado = false
    if (!is_encarcelado())
      resultado =  modificar_saldo(cantidad)
      Diario.instance.ocurre_evento("El jugador #{@nombre} recibe #{cantidad} euros")
    end
    return resultado
  end
  
  def salir_carcel_pagando
    salir = false
    if(puede_salir_carcel_pagando==true && is_encarcelado()==true)
      salir=true
      paga(@@precioLibertad)
      @encarcelado = false
      Diario.instance.ocurre_evento("El jugador #{@nombre} sale de la carcel pagando")
    end
    return salir
  end 
  
  def salir_carcel_Tirando
    salir = false
    if (Dado.instance.salgo_de_la_carcel)
      salir = true
      @encarcelado = false
      Diario.instance.ocurre_evento("El jugador #{@nombre} sale de la carcel tirando")
    end
    return salir
  end
  
  def tiene_algo_que_gestionar
    tiene_algo = false
    if(@propiedades.length() > 0)
      tiene_algo = true
    end
    return tiene_algo
  end
  
  def tiene_salvoconducto
    tiene = true
    if (@salvoconducto==nil)
      tiene = false
    end
    return tiene
  end  

  def to_string
    return "Jugador{ nombre=#{@nombre}, encarcelado=#{@encarcelado}, numCasillaActual=#{@numCasillaActual}, puedeComprar=#{@puedeComprar}, saldo=#{@saldo} }"
  end
  
  def vender(ip)
    resultado = false
    if (is_encarcelado()==false && existe_la_propiedad(ip)==true)
      resultado = @propiedades.at(ip).vender(self)
      if resultado
        Diario.instance.ocurre_evento("Se ha vendido la propiedad #{@propiedades.at(ip).nombre}")
        @propiedades.delete(@propiedades.at(ip))
      end
    end
    return resultado
  end
  
  protected :jugador
  
  attr_accessor :casasMax, :CasasPorHotel, :hotelesMax, :nombre, :numCasillaActual, 
               :precioLibertad, :saldo, :puedeComprar, :encarcelado, :salvoconducto, :propiedades
end
end