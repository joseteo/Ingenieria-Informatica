package build;

public class Electronica {
    private boolean abs; 
    private boolean controlCrucero ;
    private boolean controlTraccion;
    private boolean repartoFrenada;
    
    public Electronica(boolean abs, boolean controlCrucero, boolean controlTraccion, boolean repartoFrenada){
        this.abs = abs;
        this.controlCrucero = controlCrucero;
        this.controlTraccion = controlTraccion;
        this.repartoFrenada = repartoFrenada ;
    }
    
    public boolean getAbs( ) {
       return this.abs ;
    }

    public boolean getControlCrucero() {
        return this.controlCrucero ;
    }

    public boolean getControlTraccion( ) {
        return this.controlTraccion;
    }

    public boolean getRepartoFrenada( ) {
        return this.repartoFrenada;
    }

}
