require_relative 'operaciones_juego'
require_relative 'salidas_carcel'
require_relative 'diario'

module Civitas

class Vistatextual
  def initialize
    @juegomodel=nil
    @igestion=-1
    @ipropiedad=-1
    @separador = "====================="
  end
  
  def mostarestado(estado)
    puts estado
  end
  
  def pausa
    puts "Pulsa una tecla"
    @in = gets.chomp
  end
  
  def lee_entero(max, msg1, msg2)
    numero = -1
    begin
      
      puts msg1
      cadena = gets
      
      begin
        numero = Integer(cadena)
        ok = true
        
      rescue
        puts msg2
        ok = false
        
      end
      
      if ok && (numero<0 || numero >= max)
        puts msg2
        ok = false
      end
      
    end while (!ok)
    
    return numero
  end
  
  def menu(titulo,lista)
    tab = "  "
    puts titulo
    
    for i in 0...lista.length
      puts "#{tab}#{i}-#{lista[i]}"
    end
    
    
    opcion = lee_entero(lista.length, "\n#{tab}Elige una opción: ", "#{tab}Valor erróneo")
    
    return opcion
  end
  
  def salir_carcel
    opcion = menu("Elige la forma para intentar salir de la carcel", lista = ["Pagando", "Tirando el dado"])
    opcion = opcion.to_s
    if opcion.chomp.eql? '0'
      return Salidas_carcel::PAGANDO
    elsif opcion.chomp.eql? '1'
      return Salidas_carcel::TIRANDO
    end
  end
  
  def comprar()
    opcion = menu("Elige si desea comprar la calle a la que se ha llegado", lista = ["NO", "SI"])
    opcion = opcion.to_s 
    if opcion.chomp.eql? '0'
      return Respuestas::NO
    elsif opcion.chomp.eql? '1'
      return Respuestas::SI
    end
  end
  
  def gestionar
    @igestion = menu("¿Cuál es el número de gestion inmobiliaria elegida?",
              lista = ["VENDER","HIPOTECAR","CANCELAR_HIPOTECA",
                      "CONSTRUIR_CASA","CONSTRUIR_HOTEL","TERMINAR"])
    lista = Array.new
    for i in 0...@juegomodel.getjugadoractual.propiedades.length
      lista.push(@juegomodel.getjugadoractual.propiedades.at(i).nombre.to_str)
    end
    @ipropiedad = menu("¿Cuál es la propiedad del jugador actual sobre la que se desea realizar la gestion", lista)
  end
  
  def getgestion
    return @igestion
  end
  
  def getpropiedad
    return @ipropiedad
  end
  
  def mostrar_siguiente_operacion(operacion)
    puts("La siguiente operacion que va a realizar el juego es #{operacion}")
  end
  
  def mostrar_eventos
    while Diario.instance.eventos_pendientes()
          puts("Eventos pendientes = #{Diario.instance.leer_evento()}")
    end
  end
  
  def set_civitas_juego(civitas)
    @juegomodel = civitas
    actualizar_vista()
  end
  
  def actualizar_vista
    puts("#{@separador}\nESTADO ACTUAL DEL JUEGO\n#{@separador}")
    puts("#{@separador}\nJugadorActual = #{@juegomodel.getjugadoractual().to_string()}")
    if (@juegomodel.getjugadoractual().propiedades.length > 0)
        puts("#{@separador}\nSus propiedades =")
        for i in 0...@juegomodel.jugadores.at(@juegomodel.indiceJugadoractual).propiedades.length
            puts("#{@juegomodel.jugadores.at(@juegomodel.indiceJugadoractual).propiedades.at(i).tostring()}")
        end
    else
        puts("#{@separador}\nSus propiedades = No tiene ninguna propiedad")
    end
      
    puts("#{@separador}\nCasillaActual = #{@juegomodel.getcasillaactual().to_string()}\n#{@separador}")
  end
  
end
end