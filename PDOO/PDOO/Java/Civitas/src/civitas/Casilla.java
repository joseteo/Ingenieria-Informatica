
package civitas;

import java.util.ArrayList;

public class Casilla {
    
    private static int carcel;
    private float importe;
    private String nombre;
    
    private TipoCasilla tipo;
    private TituloPropiedad tituloPropiedad;
    private Sorpresa sorpresa;
    private MazoSorpresas mazo;
    
    Casilla(String nombre){
        //Para crear la casilla de tipo descanso
        init();
        this.nombre = nombre;
        tipo = TipoCasilla.DESCANSO;
    }
    
    Casilla(TituloPropiedad titulo){
        //Para crear la casilla de tipo calle
        init();
        importe = titulo.getPrecioCompra();
        tipo = TipoCasilla.CALLE;
        nombre = titulo.getNombre();
        tituloPropiedad = titulo;
    }
    
    Casilla(float cantidad, String nombre){
        //Para crear la casilla de tipo impuesto
        init();
        tipo = TipoCasilla.IMPUESTO;
        this.nombre = nombre;
        importe = cantidad;           
    }
    
    Casilla(int numCasillaCarcel, String nombre){
        //Para crear la casilla de tipo juez
        init();
        tipo = TipoCasilla.JUEZ;
        this.nombre = nombre;
        carcel = numCasillaCarcel;
        
    }
    
    Casilla(MazoSorpresas mazo, String nombre){
        //Para crear la casilla de tipo sorpresa
        init();
        tipo = TipoCasilla.SORPRESA;
        this.nombre = nombre;
        this.mazo = mazo;
    }
    
    public String getNombre(){
        return nombre;
    }
    
    TituloPropiedad getTituloPropiedad(){
        return tituloPropiedad;
    }
    
    private void informe(int iactual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("El jugador " + todos.get(iactual).getNombre() + " ha caido en la casilla con informacion " + toString());
    }
    
    private void init(){
        carcel = 0;
        importe = 0;
        nombre = "";
        tipo = null;
    }
    
    public Boolean jugadorCorrecto(int iactual, ArrayList<Jugador> todos){
        Boolean resultado= false;
        if (iactual >= 0 && iactual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    void recibeJugador(int iactual, ArrayList<Jugador> todos){
       if (tipo == TipoCasilla.CALLE){
            recibeJugador_calle(iactual, todos);
        } else if (tipo == TipoCasilla.IMPUESTO){
            recibeJugador_impuesto(iactual, todos);
        } else if (tipo == TipoCasilla.JUEZ){
            recibeJugador_juez(iactual, todos);
        } else if (tipo == TipoCasilla.SORPRESA){
            recibeJugador_sorpresa(iactual, todos);
        } else {
            informe(iactual, todos);
        }
    }
    
    private void recibeJugador_calle(int iactual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(iactual, todos)){
            informe(iactual, todos);
            Jugador jugador = new Jugador(todos.get(iactual));
            if (!tituloPropiedad.tienePropietario()){
                jugador.puedeComprarCasilla();
            } else {
                tituloPropiedad.tramitarAlquiler(jugador);
            }
        }
    }
    
    private void recibeJugador_impuesto(int iactual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(iactual, todos)){
            informe(iactual, todos);
            todos.get(iactual).pagaImpuesto(importe);
        }
    }
    
    private void recibeJugador_juez(int iactual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(iactual, todos)){
            informe(iactual, todos);
            todos.get(iactual).encarcelar(carcel);
        }
    }
    
    private void recibeJugador_sorpresa(int iactual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(iactual, todos)){
            sorpresa = mazo.siguiente();
            informe(iactual, todos);
            sorpresa.aplicarAJugador(iactual, todos);
        }
    }
    
    @Override
    public String toString(){
        return "Casilla{ tipo = " + tipo + ", carcel = " + carcel + ", importe = " +
                importe + ", nombre = " + nombre + "}";
    }
            
}
