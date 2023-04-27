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
public class SorpresaConvertirme extends Sorpresa{

    SorpresaConvertirme() {
        super("Debes convertirte en especulador");
        
    }
    
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        informe(actual, todos);
        JugadorEspeculador especulador = todos.get(actual).convertir();
        todos.set(actual, especulador);
    }
    
}
