module Civitas

class Casilla_juez < Casilla
  
  def initialize(numCasillaCarcel, nombre)
    super(nombre)
    @carcel=numCasillaCarcel
  end
  
  def recibejugador(iactual, todos)
    if(jugador_correcto(iactual, todos))
      informe(iactual, todos)
      todos.at(iactual).encarcelar(@carcel)
    end
  end
  
  def to_string()
    return "#{super}, { carcel= #{@carcel} }"
  end
  
end
end