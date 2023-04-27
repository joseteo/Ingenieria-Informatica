module Civitas

class Casilla_sorpresa < Casilla
  
  def initialize(mazo, nombre)
    super(nombre)
    @mazo=mazo
  end
  
  def recibejugador(iactual, todos)
    if(jugador_correcto(iactual, todos))
      @sorpresa= @mazo.siguiente
      informe(iactual, todos)
      @sorpresa.aplicar_a_jugador(iactual, todos)
    end
  end
  
  def to_string()
    return "#{super}"
  end
  
end
end