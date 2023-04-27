module Civitas

class Casilla
  
  def initialize(nombre)
    @nombre=nombre
  end
  
  def informe(iactual, todos)
    Diario.instance.ocurre_evento("El jugador #{todos.at(iactual).nombre} ha caido en la casilla con informacion #{to_string}")
  end
  
  def jugador_correcto(iactual, todos)
    resultado=false
    if ((iactual>=0) and (iactual <todos.length()))
      resultado=true
    end
    return resultado
  end
  
  def recibejugador(iactual, todos)
    informe(iactual, todos)
  end
  
  def to_string
    return "Casilla{ nombre= #{@nombre} }"
  end
  
  
  attr_accessor :nombre
end
end