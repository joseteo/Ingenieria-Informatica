package build;

public class MotoBuilder implements Builder {
    private MotoTipo tipo; 
    private Chasis chasis; 
    private Asiento asiento; 
    private Motor motor; 
    private TrenRodaje trenRodaje; 
    private Electronica electronica;

    @Override
    public void setMotoTipo(MotoTipo tipo){
        this.tipo = tipo;
    }
    @Override
    public void setChasis(Chasis chasis){
        this.chasis = chasis ;
    }
    @Override
    public void setAsientos(Asiento asiento){
        this.asiento = asiento;
    }
    @Override
    public void setMotor(Motor motor){
        this.motor = motor;
    }
    @Override
    public void setTrenRodaje(TrenRodaje trenRodaje){
        this.trenRodaje = trenRodaje;
    }
    @Override
    public void setElectronica(Electronica electronica){
        this.electronica = electronica ;
    }
    public Moto EntregaMoto() {
        return new Moto(tipo, chasis, asiento, motor, trenRodaje, electronica);
    }
}
