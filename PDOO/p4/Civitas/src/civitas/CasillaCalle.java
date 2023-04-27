
package civitas;

import java.util.ArrayList;

public class CasillaCalle extends Casilla {
    private float importe;
    
    private TituloPropiedad tituloPropiedad;
    
    CasillaCalle(TituloPropiedad titulo){
        //Para crear la casilla de tipo calle
        super(titulo.getNombre());
        importe = titulo.getPrecioCompra();
        tituloPropiedad = titulo;
    }
    
    
    @Override
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        if (super.jugadorCorrecto(iactual, todos)){
            super.informe(iactual, todos);
            if (tituloPropiedad.tienePropietario() == false){
                todos.get(iactual).puedeComprarCasilla();
                todos.get(iactual).puedeComprar = true;
            } else {
                tituloPropiedad.tramitarAlquiler(todos.get(iactual));
                todos.get(iactual).puedeComprar = false;
            }
        }
    }
    
    TituloPropiedad getTituloPropiedad(){
        return tituloPropiedad;
    }
    
    @Override
    public String toString(){
        return "Casilla{ nombre=" + super.getNombre() + ", importe=" + importe + " }";
    }
    
}
