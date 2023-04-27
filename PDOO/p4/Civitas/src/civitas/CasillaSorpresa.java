
package civitas;

import java.util.ArrayList;

public class CasillaSorpresa extends Casilla {
    private MazoSorpresas mazo;
    private Sorpresa sorpresa;
    CasillaSorpresa(MazoSorpresas mazo, String nombre){
        //Para crear la casilla de tipo sorpresa
        super(nombre);
        this.mazo = mazo;
    }
    
    @Override
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        if (super.jugadorCorrecto(iactual, todos)){
            sorpresa = mazo.siguiente();
            super.informe(iactual, todos);
            sorpresa.aplicarAJugador(iactual, todos);
        }
    }
    
    @Override
    public String toString(){
        return "Casilla{ nombre=" + super.getNombre() + " }";
    }
}
