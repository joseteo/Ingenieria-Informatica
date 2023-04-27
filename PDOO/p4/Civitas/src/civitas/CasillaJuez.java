
package civitas;

import java.util.ArrayList;

public class CasillaJuez extends Casilla {
    private static int carcel;
    
    CasillaJuez(int numCasillaCarcel, String nombre){
        //Para crear la casilla de tipo juez
        super(nombre);
        carcel = numCasillaCarcel;
    }
    
    @Override
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        if (super.jugadorCorrecto(iactual, todos)){
            super.informe(iactual, todos);
            todos.get(iactual).encarcelar(carcel);
        }
    }
    
    @Override
    public String toString(){
        return "Casilla{ nombre=" + super.getNombre() + ", carcel=" + carcel + " }";
    }
}
