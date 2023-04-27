module Civitas
  
class Sorpresa_salircarcel < Sorpresa
  
  def initialize(mazo)
    super("Quedas libre de la carcel")
    @mazo = mazo
  end
  
  
  def aplicar_a_jugador(actual, todos)
    
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      poseido = false
      
      for i in 0...todos.length
        
        if todos.at(i).tiene_salvoconducto
          poseido = true
        end
      end
      
      if !poseido
        todos.at(actual).obtener_salvoconducto(self)
        salirdelmazo
      end
    end
  end
  
  def salirdelmazo
    @mazo.inhabilitar_carta_especial(self)
  end
  
  def usada
    @mazo.habilitar_carta_especial(self)
  end
  
  def to_string()
    return super
  end
  
end
end