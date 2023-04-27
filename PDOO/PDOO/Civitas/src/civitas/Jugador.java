/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author joseteo
 */
public class Jugador implements Comparable<Jugador>{
    
    static protected int CasasMax = 4;
    static protected int CasasPorHotel = 4;
    private int casillaActual;
    static protected int HotelesMax = 4;
    private String nombre;
    static protected float PasoPorSalida = 1000;
    private boolean puedeComprar;
    private float saldo;
    static private float SaldoInicial = 7500;
    private ArrayList<CasillaCalle> propiedades;
    
    
    JugadorEspeculador convertir(){
        JugadorEspeculador especulador = new JugadorEspeculador(this);
        return especulador;
    }
    
    
    
    int cantidadCasasHoteles(){
        int aux = 0;
        for (int i=0; i < propiedades.size(); i++)
            aux += propiedades.get(i).cantidadCasasHoteles();
        return aux;
    }
    
    @Override
    public int compareTo(Jugador otro){
        return Float.compare(this.saldo, otro.saldo);
    }
    
    boolean comprar(CasillaCalle titulo){
        boolean result = false;
        if(!titulo.tienepropietario()){
            if(puedeComprar){
                float precio = titulo.getPrecioCompra();
                if(puedoGastar(precio)){
                    result = titulo.comprar(this);
                    if(result){
                        propiedades.add(titulo);
                        Diario.getInstance().ocurreEvento("El jugador "+nombre+" compra la propiedad "+titulo.getNombre());
                    }
                    puedeComprar=false;
                }else
                    Diario.getInstance().ocurreEvento("El jugador "+nombre+" no tiene saldo para comprar la propiedad "+titulo);
            }
        }
        return result;
    }
    
    boolean construirCasa(int ip){
        boolean result = false;
        boolean existe = existeLaPropiedad(ip);
        if(existe){
            CasillaCalle propiedad = propiedades.get(ip);
            boolean puedoEdificar = puedoEdificarCasa(propiedad);
            float precioEdificar = propiedad.getPrecioEdificar();
            if(puedoGastar(precioEdificar) && propiedad.getNumcasas()<getCasasMax())
                puedoEdificar = true;
            if(puedoEdificar){
                
                propiedad.construirCasa();
                Diario.getInstance().ocurreEvento("El jugador "+nombre+" construye una casa en la propiedad "+ip+", la propiedad tiene "+propiedad.getNumcasas()+" casas y "+propiedad.getNumHoteles()+" hoteles");
            }
        }
        return result;
    }
    
    boolean construirHotel(int ip){
        boolean result = false;
        if (existeLaPropiedad(ip)){
            CasillaCalle propiedad = propiedades.get(ip);
            boolean puedoEdificarHotel = puedoEdificarHotel(propiedad);
            puedoEdificarHotel = false;
            float precio = propiedad.getPrecioEdificar();
            if (puedoGastar(precio)){
                if (propiedad.getNumHoteles()<getHotelesMax())
                    if (propiedad.getNumcasas()>=getCasasMax())
                        puedoEdificarHotel = true;
            }
            if(puedoEdificarHotel){
                result = propiedad.construirHotel();
                propiedad.derruirCasas(CasasPorHotel, this);
                Diario.getInstance().ocurreEvento("El jugador "+nombre+" construye hotel en la propiedad "+ip+", la propiedad tiene "+propiedad.getNumcasas()+" casas y "+propiedad.getNumHoteles()+" hoteles");
            }
                
        }
            
        return result;
    }
    
    boolean enBancarrota(){
        boolean result = false;
        if (saldo<=0)
            result = true;
        return result;
    }
    
    boolean existeLaPropiedad(int ip){
        boolean aux = false;
        if (propiedades.get(ip) != null)
            aux = true;
        return aux;
    }
    
     int getCasasMax(){
        return CasasMax;
    }
    
    int getCasasPorHotel(){
        return CasasPorHotel;
    }
    
    public int getCasillaActual(){
        return this.casillaActual;
    }
    
     int getHotelesMax(){
        return HotelesMax;
    }
    
    public String getNombre(){
        return this.nombre;
    }
    
    private float getPremioPasoSalida(){
        return PasoPorSalida;
    }
    
    /*protected*/ public ArrayList<CasillaCalle> getPropiedades(){
        return this.propiedades;
    }
    
    boolean getPuedeComprar(){
        return this.puedeComprar;
    }
    
    public float getSaldo(){
        return this.saldo;
    }

    Jugador(String nombre){
        this.nombre = nombre;
        casillaActual = 0;
        puedeComprar = true;
        saldo = 7500;
        propiedades = new ArrayList<>();
    }
    
    //constructor copia
    public Jugador(Jugador otro){
        this.nombre = otro.nombre;
        this.casillaActual = otro.casillaActual;
        this.puedeComprar = otro.puedeComprar;
        this.saldo = otro.saldo;
        this.propiedades = otro.propiedades;
    }
    
    boolean modificarSaldo(float cantidad){
        this.saldo += cantidad;
        Diario.getInstance().ocurreEvento("Al jugador " + this.nombre + " se le ha modificado el saldo a " + saldo + toString());
        return true;
    }
    
    boolean moverACasilla(int numCasilla){
        this.casillaActual = numCasilla;
        this.puedeComprar = true;
        Diario.getInstance().ocurreEvento("El jugador " + this.nombre + " se ha movido a la casilla" + numCasilla);
        return true;
    }
    
    boolean paga(float cantidad){
        cantidad = cantidad *-1;
        boolean result = modificarSaldo(cantidad);
        return result;
    }
    
    public boolean pagaAlquiler(float cantidad){
        boolean result = paga(cantidad);
        return result;
    }
    
    boolean pasaPorSalida(){
        recibe(getPremioPasoSalida());
        Diario.getInstance().ocurreEvento("El jugador " + this.nombre + " ha pasado por la casilla de salida " + toString());
        return true;
    }
    
    boolean puedeComprarCasilla(){
        this.puedeComprar = true;
        return puedeComprar;
    }
    
     boolean puedoEdificarCasa(CasillaCalle propiedad){
        boolean aux = false;
        float precio = propiedad.getPrecioEdificar();
        if (puedoGastar(precio) && propiedad.getNumcasas() < getCasasMax()){
            aux = true;
        }
        return aux;
    }
    
     boolean puedoEdificarHotel(CasillaCalle propiedad){
        boolean aux = false;
        float precio = propiedad.getPrecioEdificar();
        if (puedoGastar(precio)){
            if (propiedad.getNumHoteles() < getHotelesMax()){
                if (propiedad.getNumcasas() >= getCasasPorHotel()){
                    aux = true;
                }
            }
        }
        return aux;
    }
    
     boolean puedoGastar(float precio){
        return precio <= this.saldo;
    }
    
    boolean recibe(float cantidad){
        boolean result = this.modificarSaldo(cantidad);
        return result;
    }
    
    boolean tieneAlgoQueGestionar(){
        boolean result = false;
        if (this.propiedades.size() > 0)
            result = true;
        return result;
    }
    
    @Override
    public String toString(){
        return "Jugador{ nombre= " + nombre +  ", numCasillaActual= " + casillaActual + ", puedeComprar= " + puedeComprar +
                ", saldo= " + saldo + ", propiedades= " + propiedades + "}\n";
    }
    
}
