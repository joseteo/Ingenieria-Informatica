require_relative 'estados_juego'
require_relative 'operaciones_juego'
require_relative 'diario'

module Civitas

class Gestorestados
  
  def estado_inicial
    return Estadosjuego::INICIO_TURNO
  end
  
  def operaciones_permitidas(jugador, estado)
    op=nil
    
    if estado==Estadosjuego::INICIO_TURNO
      if jugador.encarcelado
        op=Operacionesjuego::SALIR_CARCEL
      else
        op=Operacionesjuego::AVANZAR
      end
      
    elsif estado==Estadosjuego::DESPUES_CARCEL
      op = Operacionesjuego::PASAR_TURNO
      
    elsif estado== Estadosjuego::DESPUES_AVANZAR
      if jugador.encarcelado
        op = Operacionesjuego::PASAR_TURNO
      elsif jugador.puedeComprar
        op = Operacionesjuego::COMPRAR
      elsif jugador.tiene_algo_que_gestionar
        op = Operacionesjuego::GESTIONAR
      else
        op = Operacionesjuego::PASAR_TURNO
      end
      
      
    elsif estado==Estadosjuego::DESPUES_COMPRAR
      if jugador.tiene_algo_que_gestionar
        op = Operacionesjuego::GESTIONAR
      else
        op = Operacionesjuego::PASAR_TURNO
      end
      
    elsif estado==Estadosjuego::DESPUES_GESTIONAR
      op=Operacionesjuego::PASAR_TURNO
    end
    
    return op
  end
  
  def siguiente_estado(jugador,estado,operacion)
      siguiente = nil

      case estado

      when Estadosjuego::INICIO_TURNO
        if (operacion==Operacionesjuego::SALIR_CARCEL)
          siguiente = Estadosjuego::DESPUES_CARCEL
        else
          if (operacion==Operacionesjuego::AVANZAR)
            siguiente = Estadosjuego::DESPUES_AVANZAR
          end
        end


      when Estadosjuego::DESPUES_CARCEL
        if (operacion==Operacionesjuego::PASAR_TURNO)
          siguiente = Estadosjuego::INICIO_TURNO
        end

      when Estadosjuego::DESPUES_AVANZAR
        case operacion
          when Operacionesjuego::PASAR_TURNO
            siguiente = Estadosjuego::INICIO_TURNO
          when
            Operacionesjuego::COMPRAR
              siguiente = Estadosjuego::DESPUES_COMPRAR
          when Operacionesjuego::GESTIONAR
              siguiente = Estadosjuego::DESPUES_GESTIONAR
        end


      when Estadosjuego::DESPUES_COMPRAR
        #if (jugador.tiene_algo_que_gestionar)
        if (operacion==Operacionesjuego::GESTIONAR)
          siguiente = Estadosjuego::DESPUES_GESTIONAR
        #  end
        else
          if (operacion==Operacionesjuego::PASAR_TURNO)
            siguiente = Estadosjuego::INICIO_TURNO
          end
        end

      when Estadosjuego::DESPUES_GESTIONAR
        if (operacion==Operacionesjuego::PASAR_TURNO)
          siguiente = Estadosjuego::INICIO_TURNO
        end
      end

      Diario.instance.ocurre_evento("De: "+estado.to_s+ " con "+operacion.to_s+ " sale: "+siguiente.to_s)

      return siguiente
    end
end
end
