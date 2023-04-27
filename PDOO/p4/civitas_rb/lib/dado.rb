require_relative 'diario'
require 'singleton'

module Civitas
class Dado
  include Singleton
  
  def initialize
    @debug=true
    @ultimoResultado=0
  end
  
  Dado.instance
  
  def tirar
    if @debug==true
      resultado=1
    else
      resultado= rand(0..5) + 1
    end
    @ultimoResultado=resultado
    return resultado
  end
  
  def salgo_de_la_carcel()
    resultado=false
    if tirar()==6
      resultado=true
    end
    return resultado
  end
  
  def quien_empieza(n)
    return rand(0...n)
  end
  
  def setdebug(d)
    @debug=d
    if @debug==true
      Diario.instance.ocurre_evento("dado debug true")
    else
      Diario.instance.ocurre_evento("dado debug false")
    end
  end
  
  attr_accessor :debug, :SalirCarcel, :ultimoResultado
  
end
end