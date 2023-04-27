require 'singleton'
 
module Civitas
class Diario
  include Singleton
  
  def initialize
    @eventos=[]
  end
  
  Diario.instance
  
  def diario
    @eventos=Array.new
  end
  
  def ocurre_evento(e)
    @eventos.push(e)
  end
  
  def eventos_pendientes
    return !@eventos.empty?
  end
  
  def leer_evento
    salida=""
    if(!@eventos.empty?)
      salida= @eventos.delete_at(0)
    end
    return salida
  end
  
  attr_accessor :eventos
  
  private :diario
end
end