require_relative 'jugador'

module Civitas

class Titulo_propiedad
  
  @@factorintereseshipoteca=1.1
  
  def initialize(nom, ab, fr, hb, pc, pe)
    @nombre=nom
    @alquilerbase=ab
    @factorrevalorizacion=fr
    @factorintereseshipoteca= 1.1
    @hipotecabase=hb
    @preciocompra=pc
    @precioedificar=pe
    @hipotecado=false
    @numcasas=0
    @numhoteles=0
    @propietario=nil
  end
  
  def actualizar_propietario_por_conversion(jugador)
    @propietario=jugador
  end
  
  def cancelar_hipoteca(jugador)
    operacionrealizada=false
    if @hipotecado and es_este_el_propietario(jugador)
      @propietario.paga(getimportecancelarhipoteca)
      @hipotecado=false
      operacionrealizada=true
    end
    return operacionrealizada
  end
  
  def cantidadcasashoteles
    return (@numcasas+@numhoteles)
  end
  
  def comprar(jugador)
    resultado=false
    if !tienepropietario
      actualizar_propietario_por_conversion(jugador)
      @propietario.paga(@preciocompra)
      resultado=true
    end
    return resultado
  end
  
  def construircasa(jugador)
    resultado=false
    if es_este_el_propietario(jugador)
      @propietario.paga(@precioedificar)
      @numcasas=@numcasas+1
      resultado=true
    end
    return resultado
  end
  
  def construirhotel(jugador)
    resultado=false
    if es_este_el_propietario(jugador)
      @propietario.paga(5 * @precioedificar)
      @numhoteles=@numhoteles+1
      resultado=true
    end
    return resultado
  end
  
  def derruircasas(n, jugador)
    operacionrealizada=false
    if es_este_el_propietario(jugador) and @numcasas>=n
      @numcasas=@numcasas-n
      operacionrealizada=true
    end
    return operacionrealizada
  end
  
  def es_este_el_propietario(jugador)
    resultado=false
    if @propietario==jugador
      resultado=true
    end
    return resultado
  end
  
  def getimportecancelarhipoteca
    return (getimportehipoteca * @factorintereseshipoteca)
  end
  
  def getimportehipoteca
    cantidadrecibida= (1+ (@numcasas * 0.5) + (@numhoteles * 2.5)) * @hipotecabase
    return cantidadrecibida
  end
    
  def getprecioalquiler
    precioalquiler = (1 + (@numcasas*0.5) + (@numhoteles*2.5)) * @alquilerbase
    if @hipotecado or propietarioencarcelado
      precioalquiler=0
    end
    return precioalquiler
  end
  
  def getprecioventa
    precioventa = @preciocompra + (@numcasas + 5 * @numhoteles) * @precioedificar * @factorrevalorizacion
    return precioventa
  end
  
  def hipotecar(jugador)
    operacionrealizada =false
    if !@hipotecado and es_este_el_propietario(jugador)
      @propietario.recibe(getimportehipoteca)
      @hipotecado=true
      operacionrealizada=true
    end
    return operacionrealizada
  end
  
  def propietarioencarcelado
    resultado=false
    if tienepropietario
      resultado=@propietario.encarcelado
    end
    return resultado
  end
  
  def tienepropietario
    resultado= false
    if @propietario != nil
      resultado=true
    end
    return resultado
  end
  
  def tostring
    return "TituloPropiedad { nombre=#{@nombre}, hipotecada=#{@hipotecado}, precio de compra=#{@preciocompra}, alquilerBase= #{@alquilerbase},
                  factorRevalorizacion=#{@factorrevalorizacion}, hipotecaBase=#{@hipotecabase}, precioEdificar= #{@precioedificar}, numero de hoteles=#{@numhoteles},
                  numero de casas=#{@numcasas} }"
  end
  
  def tramitaralquiler(jugador)
    if tienepropietario and !es_este_el_propietario(jugador)
      jugador.paga_alquiler(getprecioalquiler)
      @propietario.recibe(getprecioalquiler)
    end
  end
  
  def vender(jugador)
    resultado=false
    if es_este_el_propietario(jugador)
      @propietario.recibe(getprecioventa)
      @numcasas=0
      @numhoteles=0
      @propietario=nil
      resultado=true
    end
    return resultado
  end
  

  attr_accessor :hipotecado, :nombre, :numcasas, :numhoteles, :preciocompra, :precioedificar, :propietario
  
  private :es_este_el_propietario, :getimportehipoteca, :getprecioalquiler
end
end