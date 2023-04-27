/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;


import civitas.Jugador;

import civitas.OperacionInmobiliaria;
import civitas.OperacionJuego;
import controladorCivitas.Respuesta;
import java.util.ArrayList;


public interface Vista{
    

    public void actualiza();
    
    public void pausa();

    public Respuesta comprar();

    public OperacionInmobiliaria elegirOperacion();

    public int elegirPropiedad();

    public void mostrarSiguienteOperacion(OperacionJuego operación);

    public void mostrarEventos();
    
    public void mostrarEstado();
    

}
