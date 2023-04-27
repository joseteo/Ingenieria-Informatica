/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author teo
 */
public class CasillaCalle extends Casilla{
    
    private float precioCompra, precioEdificar, precioBaseAlquiler;
    private int numCasas, numHoteles;
    private Jugador propietario;
    
    static final private float FACTORIALALQUILERCALLE = 1.0f, FACTORIALALQUILERCASA = 1.0f, FACTORIALALQUILERHOTEL = 4.0f;
    
    public int cantidadCasasHoteles(){
        return numCasas+numHoteles;
    }
    
    
    CasillaCalle( String titulo, float precioCompra, float precioEdificar, float precioBaseAlquiler){
        super(titulo);
        this.precioCompra = precioCompra;
        this.precioEdificar = precioEdificar;
        this.precioBaseAlquiler = precioBaseAlquiler;
    }
    
    
    @Override
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        super.informe(iactual, todos);
        Jugador jugador = todos.get(iactual);
        if(!tienepropietario())
            jugador.puedeComprarCasilla();
        else
            tramitarAlquiler(jugador);
    }
    
    boolean comprar (Jugador jugador){
        propietario = jugador;
        propietario.paga(precioCompra);
        return true;
    }
    
    public boolean construirCasa(){
        propietario.paga(precioEdificar);
        numCasas++;
        return true;
    }
    
    public boolean construirHotel(){
        propietario.paga(precioEdificar);
        numHoteles++;
        return true;
    }
    
    boolean derruirCasas(int numero, Jugador jugador){
        boolean aux = false;
        if(esEsteElPropietario(jugador)){
            if (numero <= numCasas){
                numCasas -= numero;
                aux = true;
            }
        }
        return aux;
    }
    
    public int getNumcasas(){
        return numCasas;
    }
    
    public int getNumHoteles(){
        return numHoteles;
    }
    
    public float getPrecioAlquilerCompleto(){
        //float PrecioAlquilerCompleto = precioBaseAlquiler * (1 + numCasas + numHoteles*4);
        
        //sesion 2
        float PrecioAlquilerCompleto = precioBaseAlquiler*FACTORIALALQUILERCALLE * (1 + FACTORIALALQUILERCASA*numCasas + FACTORIALALQUILERHOTEL*numHoteles);
        
        return PrecioAlquilerCompleto;
    }
    
    public float getPrecioCompra(){
        return precioCompra;
    }
    
    public float getPrecioEdificar(){
        return precioEdificar;
    }
    
    public boolean tienepropietario(){
        boolean aux = false;
        if (propietario != null)
            aux = true;
        return aux;
    }
    
    public void tramitarAlquiler(Jugador jugador){
        if (tienepropietario())
            if (!esEsteElPropietario(jugador)){
                jugador.pagaAlquiler(getPrecioAlquilerCompleto());
                propietario.recibe(getPrecioAlquilerCompleto());
            }
    }
    
    public boolean esEsteElPropietario(Jugador jugador){
        boolean aux = false;
        if (jugador.equals(propietario))
            aux = true;
        return aux;
    }
    
    public void actualizaPropietarioPorConversion(JugadorEspeculador especulador){
        propietario = especulador;
    }
    
    @Override
    public String toString(){
        String aux = (super.getNombre()+"{ Precios: Compra= " + precioCompra + 
                " Edificar= " + precioEdificar + " Alquiler Base= " + precioBaseAlquiler
                + " Casas= " + numCasas + " Hoteles= " + numHoteles + "}");
        
        if (tienepropietario())
            aux = this.propietario.getNombre();
        
        return aux;
    }
    
}
