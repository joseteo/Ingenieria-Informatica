/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controladorCivitas;

import GUI.Vista;
import civitas.CivitasJuego;
import civitas.GestionInmobiliaria;
import civitas.Jugador;
import civitas.OperacionInmobiliaria;
import civitas.OperacionJuego;
import java.util.ArrayList;
import vistaTextualCivitas.VistaTextual;

/**
 *
 * @author teo
 */
public class ControladorMIO {
    private CivitasJuego juego;
    private VistaTextual vista;

    public ControladorMIO(CivitasJuego juego, VistaTextual vista){
        this.juego = juego;
        this.vista = vista;
    }
    
    public void juega(){
        vista = new VistaTextual(juego);
        
        while (!juego.finalDelJuego()){
            vista.actualiza();
            
            vista.pausa();
            
            OperacionJuego operacionSig = juego.siguientePaso();
            vista.mostrarSiguienteOperacion(operacionSig);
            
            System.out.println("\n"+operacionSig+"\n");
            
            if (operacionSig != OperacionJuego.PASAR_TURNO){
                vista.mostrarEventos();
            }
            
            Boolean finJuego = juego.finalDelJuego();
            
            if (finJuego != true){
                switch (operacionSig){
                    
                    case COMPRAR:
                        Respuesta resp = vista.comprar();
                        if (resp == Respuesta.SI){
                           juego.comprar();
                        }
                        juego.siguientePasoCompletado(operacionSig);
                        break;
                    case GESTIONAR:
                        OperacionInmobiliaria gest = vista.elegirOperacion();
                        
                        if(gest != OperacionInmobiliaria.TERMINAR){
                            int ip = vista.elegirPropiedad();


                            GestionInmobiliaria op = new GestionInmobiliaria(gest, ip);

                            switch (op.getOperacion()){
                                case CONSTRUIR_CASA:
                                    juego.construirCasa(vista.elegirPropiedad());
                                    break;
                                case CONSTRUIR_HOTEL:
                                    juego.construirHotel(vista.elegirPropiedad());
                                    break;
                                /*case TERMINAR:
                                    juego.siguientePasoCompletado(operacionSig);
                                    break;*/
                            }
                        }else if (gest == OperacionInmobiliaria.TERMINAR)
                            juego.siguientePasoCompletado(operacionSig);
                        break;
                }
            }   
        }        
        juego.ranking();
        vista.actualiza();
    }
    
    
    
}
