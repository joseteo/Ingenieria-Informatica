
package civitas;

import java.util.ArrayList;

public class Casilla {
    private String nombre;
    
    Casilla(String nombre){
        //Para crear la casilla de tipo descanso
        this.nombre = nombre;
    }
    
    public String getNombre(){
        return nombre;
    }
    
    void informe(int iactual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("El jugador " + todos.get(iactual).getNombre() + " ha caido en la casilla con informacion " + toString());
    }
    
    public Boolean jugadorCorrecto(int iactual, ArrayList<Jugador> todos){
        Boolean resultado= false;
        if (iactual >= 0 && iactual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
       informe(iactual, todos);
    }
    
    @Override
    public String toString(){
        return "Casilla{ nombre=" + nombre + " }";
    }
            
}
