require_relative 'gestiones_inmobiliarias'

class Operaciones_inmobiliarias
  def initialize(gest, ip)
    @gestion = gest
    @numpropiedades = ip
  end

  
  attr_reader :gestion, :numpropiedades
  
end
