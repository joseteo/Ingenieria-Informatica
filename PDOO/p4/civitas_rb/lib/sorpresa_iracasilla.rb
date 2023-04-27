module Civitas
  
class Sorpresa_iracasilla < Sorpresa
  
  def initialize(tablero, valor, todos)
    super(texto)
    @tablero=tablero
    @valor=valor
  end
  
  
  def aplicar_a_jugador(actual, todos)  
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      casillaactual = todos.at(actual).numCasillaActual
      tirada = @tablero.calcular_tirada(casillaactual, @valor)
      nuevaposicion = @tablero.nueva_posicion(actual, tirada)
      todos.at(actual).mover_a_casilla(nuevaposicion)
      @tablero.get_casilla(@valor).recibejugador(actual, todos)
    end
  end
  
  def to_string()
    return super
  end
  
end
end