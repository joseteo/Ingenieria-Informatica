package build;

public class Moto {
    private MotoTipo tipo; 
    private Chasis chasis; 
    private Asiento asiento; 
    private Motor motor; 
    private TrenRodaje trenRodaje; 
    private Electronica electronica;

    public Moto(MotoTipo tipo, Chasis chasis, Asiento asiento, Motor motor, TrenRodaje trenRodaje, Electronica electronica){
        this.tipo = tipo;
        this.chasis = chasis;
        this.asiento = asiento;
        this.motor = motor;
        this.trenRodaje = trenRodaje;
        this.electronica = electronica;
    }
    
    public Asiento getAsiento() {
        return asiento;
    }
    
    public Chasis getChasis() {
        return chasis;
    }
    public Electronica getElectronica() {
        return electronica;
    }
    public Motor getMotor() {
        return motor;
    }
    public MotoTipo getTipo() {
        return tipo;
    }
    public TrenRodaje getTrenRodaje() {
        return trenRodaje;
    }
    
    @Override  
    public String toString(){
        return 
        "Tipo de moto: " + getTipo() + "\n" +
        "Tipo de asiento: " + getAsiento() + "\n" +
        "Tipo de chasis: " + getChasis() + "\n" +
        "TREN RODAJE" + "\n" +
        "\tDiametro ruedas: " + getTrenRodaje().getPulgadaRueda() + "\n" +
        "\tFrenos: " + getTrenRodaje().getTipoFrenos() + "\n" +
        "\tSuspension: " + getTrenRodaje().getTipoSuspension() + "\n" +
        
        "MOTOR" + "\n" + 
        "\tCaballos: " + getMotor().getcv() + "\n" +
        "\tCilindrada: " + getMotor().getcc() + "\n" +
        "\tKilometraje: " + getMotor().getkilometraje() + "\n" +
        "\tInyeccion: " + getMotor().getinyeccion() + "\n" +
        "ELECTRONICA" + "\n" + 
        "\tABS: " + getElectronica().getAbs() + "\n" +
        "\tReparto frenada: " + getElectronica().getRepartoFrenada() + "\n" +
        "\tControl crucero: " + getElectronica().getControlCrucero() + "\n" +
        "\tControl traccion: " + getElectronica().getControlTraccion() + "\n";
        
    }


    
}

