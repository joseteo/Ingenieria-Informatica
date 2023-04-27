/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controladorCivitas;

import GUI.Vista;
import civitas.CivitasJuego;
//import vistaTextualCivitas.VistaTextual;
import civitas.OperacionJuego;
import civitas.OperacionInmobiliaria;
import civitas.GestionInmobiliaria;
import civitas.Casilla;
import civitas.Diario;
import civitas.Jugador;
import java.util.Collections;

/**
 *
 * @author emilio
 */
public class Controlador {
    private CivitasJuego juego;
    private Vista vista;
    
    public Controlador(CivitasJuego juego, Vista vista){
       
        this.juego=juego;
        this.vista=vista;
    }
    
    public void juega(){
        while(!juego.finalDelJuego()){
            vista.mostrarEstado();
            
            vista.pausa();
            
            OperacionJuego op= juego.siguientePaso();
            vista.mostrarSiguienteOperacion(op);
            if(op != OperacionJuego.PASAR_TURNO){
                vista.mostrarEventos();
                
                if(op==OperacionJuego.COMPRAR){
                    if(vista.comprar()==Respuesta.SI){
                        if(juego.comprar()){
                            juego.siguientePasoCompletado(op);
                        }
                    }else {
                            juego.siguientePasoCompletado(op); 
                    }
                }else if(op==OperacionJuego.GESTIONAR){
                    OperacionInmobiliaria inm = vista.elegirOperacion();
                    if(inm!=OperacionInmobiliaria.TERMINAR){
                        int np = vista.elegirPropiedad();
                        GestionInmobiliaria gest = new GestionInmobiliaria(inm,np);
                        if(null!=gest.getOperacion())switch (gest.getOperacion()) {
                            case CONSTRUIR_CASA:
                                juego.construirCasa(np);
                                break;
                            case CONSTRUIR_HOTEL:
                                juego.construirHotel(np);
                                break;
                        }   
                    }else{
                        juego.siguientePasoCompletado(op);
                    }
                }
            }
            vista.actualiza();
            //añadir aqui pagar el alquiler
        }
            //juego.finalDelJuego();
            System.out.println(juego.ranking());
            vista.mostrarEstado();
        
    }
    
    
    
    
    
    
    
    
    
    
    
}
