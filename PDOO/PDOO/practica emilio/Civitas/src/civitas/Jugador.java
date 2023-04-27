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
public class Jugador implements Comparable<Jugador> {
    //Atributos de clase
    private ArrayList<Casilla> propiedades;
    protected static int CasasMax=4;
    protected static int CasasPorHotel=4;
    protected static int HotelesMax=4;
    protected static float PasoPorSalida=1000;
    private static final float SaldoInicial=7500;
    
    
    //Atributos de instancia
    private String nombre;
    private int casillaActual;
    private float saldo;
    private boolean puedeComprar;
    
    
    //metodos
    
    int cantidadCasasHoteles(){
        return CasasPorHotel;
    }
    //si a>b devuelve negativo
    //si a<b devuelve positivo
    //si a==b devuelve 0
   
  
    @Override
    public int compareTo(Jugador otro){
        if(this.saldo < otro.saldo){
            return -1;
        }else if(this.saldo > otro.saldo){
            return 1;
        }else{
            return 0;
                }
             
    }
    
    boolean comprar(Casilla titulo){
        boolean result =false;
        if(puedeComprar){
            float precio = titulo.getPrecioCompra();
            if(puedoGastar(precio)){
                result = titulo.comprar(this);
                if(result){
                    this.propiedades.add(titulo);
                    Diario.getInstance().ocurreEvento("El jugador " +this.nombre+ " compra la propiedad " +titulo);
                }else{
                    puedeComprar=false;
                }  
            }
            Diario.getInstance().ocurreEvento("El jugador " +this.nombre+ " no tienen saldo para comprar la propiedad " +titulo);
        }
        return result;
    }
    
    boolean construirCasa(int ip){
        boolean result = false;
        if (existeLaPropiedad(ip)){
            Casilla propiedad = propiedades.get(ip);
            boolean puedoEdificar = puedoEdificarCasa(propiedad);   //4
            float precioEdificar = propiedad.getPrecioedificar();
            if (puedoGastar(precioEdificar) && propiedad.getNumCasas() < getCasasMax()){
                puedoEdificar = true;
            }else{
                puedoEdificar=false;
            }
            
            if (puedoEdificar){
                result = true;  //5     
            } 
            Diario.getInstance().ocurreEvento("El jugador " + nombre + " construye casa en la propiedad " + ip);
        }
        return result;
    }
    boolean construirHotel(int ip){
        boolean result=false;
        if(existeLaPropiedad(ip)){
            Casilla propiedad=propiedades.get(ip);
            boolean puedoEdificarHotel = this.puedoEdificarHotel(propiedad);
            float precio= propiedad.getPrecioedificar();
            if(puedoGastar(precio)){
                if(propiedad.getNumHoteles() < getHotelesMax()){
                    if(propiedad.getNumCasas() >= getCasasPorHotel()){
                        puedoEdificarHotel=true;
                    }
                }
            }
            if(puedoEdificarHotel){
                //result = propiedad.construirHotel(this);
                result=true;
                propiedad.derruirCasas(CasasPorHotel, this);
                Diario.getInstance().ocurreEvento("El jugador " +this.nombre+ " contruye hotel en la propiedad " +ip);
            }
        }
        return result;
    }
    
    boolean enBancarrota(){
        return this.saldo < 0;
    }
    
    private boolean existeLaPropiedad(int ip){
        return propiedades.size()>=ip;
    }
    
    private int getCasasMax(){
        return CasasMax;
    }
    private int getHotelesMax(){
        return HotelesMax;
    }
    int getCasasPorHotel(){
        return CasasPorHotel;
    }
    public int getCasillaActual(){
        return this.casillaActual;
    }
    
    public String getNombre(){
        return this.nombre;
    }
    
    private float getPremioPasoSalida(){
        return PasoPorSalida;
    }
    
    public ArrayList<Casilla> getPropiedades(){
        return propiedades;
    }
    boolean getPuedeComprar(){
        return this.puedeComprar;
    }
    
    public float getSaldo(){
        return this.saldo;
    }
    //constructor
    Jugador(String nombre){
        this.nombre=nombre;
        this.casillaActual=0;
        this.puedeComprar=false;
        this.saldo=SaldoInicial;
        propiedades = new ArrayList<>();
    }
    
    public Jugador(Jugador otro){
        this.nombre=otro.nombre;
        this.casillaActual=otro.casillaActual;
        this.puedeComprar=otro.puedeComprar;
        this.saldo=otro.saldo;
        this.propiedades=otro.propiedades;
        
    }
    
    boolean modificaSaldo(float cantidad){
        this.saldo+=cantidad;
        Diario.getInstance().ocurreEvento("Se ha modificado el saldo en " + cantidad + " del jugador " + this.nombre + ". El saldo total es: " +this.saldo);
        return true;
    }
    
    boolean moverACasilla(int numCasilla){
        this.casillaActual=numCasilla;
        this.puedeComprar=false;

        Diario.getInstance().ocurreEvento("Se ha movido el jugador " + this.nombre + " a la casilla " + this.casillaActual);
        return true;
    }
    
    boolean paga(float cantidad){
        return modificaSaldo(cantidad*-1);
    }
    
    public boolean pagaAlquiler(float cantidad){
        return paga(cantidad);
    }
    
    boolean pasaPorSalida(){
        this.recibe(this.getPremioPasoSalida());
        Diario.getInstance().ocurreEvento("El jugador " + this.nombre + "ha recibido el premio del paso por la  salida");
        return true;
    }
    
    boolean puedecomprarCasilla(){
        this.puedeComprar=true;
        return true;
    }
    
    private boolean puedoEdificarCasa(Casilla propiedad){
        Casilla c= propiedad;
        if(c.getNumCasas()<= CasasMax){
            if(this.puedoGastar(c.getPrecioedificar())){
                return propiedad.construirCasa(this);
                
            }else{
                return false;
            }
        }else{ 
            System.out.println("Tienes el número máximo de Casas que puedes construir");
            return false;
        }
        
    }
    private boolean puedoEdificarHotel(Casilla propiedad){
        
        Casilla c= propiedad;
        if(c.getNumHoteles()<4 && getCasasPorHotel()==c.getNumCasas()){
            if(this.puedoGastar(c.getPrecioedificar())){
                return propiedad.construirHotel(this);
            }else{
                System.out.println("No tienes dinero para gastar");
                return false;
            }
        }else{ 
            if(c.getNumCasas()< getCasasPorHotel()){
                    System.out.println("No puedes construir un Hotel si no tienes 4 Casas construidas");
                }else{
                    System.out.println("Tienes el número máximo de Hoteles que puedes construir");
                }
            return false;
        }
        
    }
    
    private boolean puedoGastar(float precio){
        if(this.saldo>=precio){
            return true;
        }else{
            System.out.println("No tiene suficiente saldo para gastar");
            return false;
        }
    }
    
    boolean recibe(float cantidad){
        return modificaSaldo(cantidad);
    }
    
    boolean tieneAlgoQueGestionar(){
        return !this.propiedades.isEmpty();
    }
    //metodo que devuelve un arraylist solo con los nombres de las propiedades
    //el metodo recorre todas las propiedades y las devuelve en formato STRING (Solo el nombre)
    //Utilizado en VISTATEXTUAL
    public ArrayList<String> getPropiedadesNombre(){
        ArrayList<String> nombrep=new ArrayList<>();
        for(int i=0;i<propiedades.size();i++){
            nombrep.add(propiedades.get(i).getNombre());
        }
        return nombrep;
    }
    @Override
	public String toString() {
		
 		return "El jugador " + this.nombre + ", esta en la casilla: " + this.casillaActual + " y tiene un saldo: " + this.saldo + "€";
	}	
    
    
    
    
    
}
