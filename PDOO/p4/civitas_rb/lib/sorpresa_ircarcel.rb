module Civitas
  
class Sorpresa_ircarcel < Sorpresa
  
  def initialize(tablero)
    super("Debes ir a la carcel")
    @tablero=tablero
  end
  
  
  def aplicar_a_jugador(actual, todos) 
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      todos.at(actual).encarcelar(@tablero.numCasillaCarcel)
    end
  end
  
  def to_string()
    return super
  end
  
end
end