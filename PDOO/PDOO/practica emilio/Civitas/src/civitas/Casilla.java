/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author emilio
 */
public class Casilla {
    //Relacciones
    private TipoCasilla tipo;
    private MazoSorpresas mazo;
    private Sorpresa sorpresa;
    private Jugador propietario;
    
    //atributos de clase
    static final float FACTORALQUILER=1;
    static final float FACTORALQUILERCASA=1;
    static final float FACTORALQUILERHOTEL=4;
    
    //Atributos de instancia

    private String nombre;
    private float precioCompra, precioEdificar, precioBaseAlquiler;
    private int numCasas, numHoteles;
    
    void init(){
        this.nombre=null;
        this.precioCompra=0;
        this.precioEdificar=0;
        this.precioBaseAlquiler=0;
        this.numCasas=0;
        this.numHoteles=0;
        mazo=null;
        sorpresa=null;
        tipo=null;
        propietario=null;
    }
    Casilla(String unNombre){
        init();
        this.tipo=TipoCasilla.DESCANSO;
        this.nombre=unNombre;
    
    }
    
    Casilla(String titulo, float PrecioCompra, float PrecioEdificar, float PrecioAlquilerBase){
        init();
        
        this.tipo=TipoCasilla.CALLE;
        this.nombre=titulo;
        this.precioCompra=PrecioCompra;
        this.precioEdificar=PrecioEdificar;
        this.precioBaseAlquiler=PrecioAlquilerBase;
        this.numCasas=0;
        this.numHoteles=0;
    }
    
    Casilla(String Nombre,MazoSorpresas mazo){
        init();
        this.mazo = mazo;
        this.tipo=TipoCasilla.SORPRESA;
        this.nombre=Nombre;
        this.precioCompra=0;
        this.precioEdificar=0;
        this.precioBaseAlquiler=0;
        this.numCasas=0;
        this.numHoteles=0;
    }
    public int cantidadCasasHoteles(){
        return this.numCasas+this.numHoteles;
    }
    
    boolean comprar(Jugador jugador){
        this.propietario=jugador;
        return propietario.paga(precioCompra);
    }
    
   
    public boolean ConstruirCasa(){
        if(this.numCasas+1 <=4){
            this.numCasas+=1;
            return true;
        }else{
            return false;
        }
    }
    boolean construirCasa(Jugador jugador){
        boolean option=false;
        if(this.numCasas+1 <=4){
            if(jugador.paga(precioEdificar)){
             this.numCasas+=1;
             option = true;
            }
        }else{
            if(this.numCasas>=4){
               System.out.println("No puedes construir más Casas. Numero="+this.numCasas); 
            }else{
               System.out.println("No se ha podido contruir la Casa. Saldo="+jugador.getSaldo()); 
            }
            option = false;
        }
        return option;
    }
    boolean construirHotel(Jugador jugador){
        boolean option=false;
        if(this.numHoteles+1 <=4 && this.numCasas==4){
            if(jugador.paga(precioEdificar)){
             this.numHoteles+=1;
             option = true;
            }
        }else{
            if(this.numCasas<4){
               System.out.println("No puedes construir un Hotel si no tienes 4 Casas"); 
            }else if(this.numHoteles>=4){
               System.out.println("No se ha podido contruir más Hoteles. Numero=" +this.numHoteles); 
            }else{
               System.out.println("No se ha podido contruir la Casa. Saldo="+jugador.getSaldo()); 
            }
            option = false;
        }
        return option;
    }
    boolean derruirCasas(int n, Jugador jugador){
        if(esEsteElPropietario(jugador) && n<=this.numCasas){
            this.numCasas-=n;
            return true;
        }else{
            return false;
        }
    }
    
    public boolean esEsteElPropietario(Jugador jugador){
        return propietario==jugador;
    }
 
    //consultores
    public String getNombre(){
        return this.nombre;
    }
    float getPrecioCompra(){
        return this.precioCompra;
    }
    
    float getPrecioedificar(){
        return this.precioEdificar;
    }
    int getNumCasas(){
        return this.numCasas;
    }
    int getNumHoteles(){
        return this.numHoteles;
    }
    float getPrecioAlquilerCompleto(){
        return this.precioBaseAlquiler*((FACTORALQUILERCASA*this.numCasas)+(this.numHoteles*FACTORALQUILERHOTEL));
    }
    
    public void tramitarAlquiler(Jugador jugador){
        if(tienePropietario() && !esEsteElPropietario(jugador)){
            jugador.pagaAlquiler(getPrecioAlquilerCompleto());
            propietario.recibe(getPrecioAlquilerCompleto());
            Diario.getInstance().ocurreEvento("El jugador " +jugador.getNombre()+" a pagado el Alquiler. Precio: " +this.getPrecioAlquilerCompleto());
        }
    }
    
    
    //modificadores
    public void setNumCasas(){
        this.numCasas+=1;
    }
    public void setNumHoteles(){
        this.numHoteles+=1;
    }
    
    
  
    
   
    
    public boolean igualdadIdentidad(Casilla otraCasilla){
        return this.equals(otraCasilla);
    }
    
    void informe(int iactual, ArrayList<Jugador> todos){
        Jugador jug=todos.get(iactual);
        Diario.getInstance().ocurreEvento("El jugador " + jug.getNombre() + ", ha caido en: " + this.toString());
    }
    
    
    void recibeJugador(int iactual, ArrayList<Jugador> todos){
       
        if(tipo == TipoCasilla.CALLE){
            recibeJugador_calle(iactual,todos);
        }else if(tipo == TipoCasilla.SORPRESA){
            recibeJugador_sorpresa(iactual, todos);
        }else if(tipo == TipoCasilla.DESCANSO){
            informe(iactual,todos);
        }
        
    }
    
    void recibeJugador_calle(int iactual, ArrayList<Jugador> todos){
        informe(iactual, todos);
        Jugador jugador=todos.get(iactual);
        if(!tienePropietario()){
            if(jugador.puedecomprarCasilla()){
                tramitarAlquiler(jugador);
            }
        }
    }
    void recibeJugador_sorpresa(int iactual, ArrayList<Jugador> todos){
            Sorpresa sorpresa = mazo.siguiente();
            informe(iactual, todos);
            sorpresa.aplicarAJugador(iactual, todos);
    }
    
    public boolean tienePropietario(){
        return this.propietario != null;
    }
    
    
    
    @Override
	public String toString() {
		if(this.propietario==null){
 		return "La Casilla es de tipo " + this.tipo + ", nombre " + this.nombre + ", Compra: " + this.precioCompra + "€ Edificacion: " + this.precioEdificar + "€ Base: " + this.precioBaseAlquiler + "€ \nNo tiene propietario";
                }else{
                    return "La Casilla es de tipo " + this.tipo + ", nombre " + this.nombre + ", Compra: " + this.precioCompra + "€ Edificacion: " + this.precioEdificar + "€ Base: " + this.precioBaseAlquiler + "€ \nEl propietario es: " + propietario;
                }
        }	
    
    
    
    
    
    
    
    
    
    
    
    
}
