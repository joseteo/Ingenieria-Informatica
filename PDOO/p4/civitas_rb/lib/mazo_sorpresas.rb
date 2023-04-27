require_relative 'sorpresa'
require_relative 'diario'

module Civitas

class Mazo_sorpresas
  
  def initialize
    @sorpresas=Array.new
    @cartasEspeciales=Array.new
    @barajada=false
    @usadas=0
    @ultimaSorpresa = Sorpresa
  end
  
  def al_mazo(sorpresa)
    if @barajada==false
      @sorpresas.push(sorpresa)
    end
  end
  
  def habilitar_carta_especial(s)
    encontrada=false
    for i in  0...@cartasEspeciales.length and !encontrada
      if @cartasEspeciales.at(i)==s
        encontrada=true
        @cartasEspeciales.delete_at(i)
        @sorpresas.push(s)
        Diario.instance.ocurre_evento("carta especial habilitada")
      end
    end
  end
  
  def inhabilitar_carta_especial(sorpresa)
    encontrada=false
    aux= @sorpresas.length
    
    for i in (0...aux)
      if !encontrada
        if @sorpresas.at(i)==sorpresa
        
          encontrada=true
          @sorpresas.delete_at(i)
          @cartasEspeciales.push(sorpresa)
          Diario.instance.ocurre_evento("carta especial inhabilitada")
        
        end
      end
      
    end
  end
  
  def mazo_sorpresas(d)
    @debug=d
    new()
    if d==true
      Diario.instance().ocurre_evento("MazoSorpresas debug true")
    end
  end
  
  def mazo_sorpresas
    new()
    @debug=false
  end
  
  def siguiente
    if ((@barajada==false) or (@usadas==@sorpresas.length))
      if @debug==false
        @sorpresas=@sorpresas.shuffle
        @usadas=0
        @barajada=true
      end
    end
    @usadas=@usadas+1
    @ultimaSorpresa = @sorpresas.at(0)
    @sorpresas.delete_at(0)
    @sorpresas.push(@ultimaSorpresa)
    
    return @ultimaSorpresa
  end
  
  attr_accessor :barajada, :debug, :usadas, :ultimaSorpresa
  
  private :initialize
end
end
