/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author aida
 */
public class TestP4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Jugador jugador = new Jugador("Jugador Original");
        
        ArrayList<Jugador> lista = new ArrayList<>();
        lista.add(jugador);
        
        TituloPropiedad propiedad = new TituloPropiedad("Calle 1", 50, 10, 150, 500, 250);
        
        lista.get(0).comprar(propiedad);
        
        System.out.println(lista.get(0).toString());
        if (lista.get(0).getPropiedades().size() > 0){
        System.out.println("Sus propiedades =");
        for (int i = 0; i < lista.get(0).getPropiedades().size(); i++ ){
            System.out.println(lista.get(0).getPropiedades().get(i).toString());
        }
      } else {
            System.out.println("Sus propiedades = No tiene ninguna propiedad");
      }
        
        SorpresaEspeculador sor = new SorpresaEspeculador(500);
        
        sor.aplicarAJugador(0,lista);
        
        System.out.println(lista.get(0).toString());
        if (lista.get(0).getPropiedades().size() > 0){
        System.out.println("Sus propiedades =");
        for (int i = 0; i < lista.get(0).getPropiedades().size(); i++ ){
            System.out.println(lista.get(0).getPropiedades().get(i).toString());
        }
      } else {
            System.out.println("Sus propiedades = No tiene ninguna propiedad");
      }

        
    }
    
}
