/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1_s1;

import factoria.*;

/**
 *
 * @author pabloxeo
 */
public class Ejercicio1_s1 {

    public static void main(String[] args) {
      
      // Usar factorias concretas y
      // crear carrera montania y carrera carretera hacerles .start
      
      FactoriaMalagaGranada fg = new factoriaGranada();        
      FactoriaMalagaGranada fm = new factoriaMalaga();
      
      fg.crearProcesion().run();
      fm.crearProcesion().run();


    }
    
}
