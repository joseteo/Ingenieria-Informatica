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
public class Sorpresa {
    //Relaciones
    MazoSorpresas mazo;
    TipoSorpresa tipo;
    
    //Atributos de instancia
    private String texto;
    private int valor;
    
    //constructor
    Sorpresa(TipoSorpresa tipo, String texto,int valor){
        this.tipo=tipo;
        this.texto=texto;
        this.valor=valor;
    }
    
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if(this.tipo==TipoSorpresa.PAGARCOBRAR){
            aplicarAJugador_pagarCobrar(actual, todos);
        }
        if(this.tipo==TipoSorpresa.PORCASAHOTEL){
            aplicarAJugador_porCasaHotel(actual, todos);
        }
    }
    
    private void aplicarAJugador_pagarCobrar(int actual, ArrayList<Jugador> todos){
        informe(actual, todos);
        Jugador jug= todos.get(actual);
        jug.modificaSaldo(this.valor);
    } 
    
    private void aplicarAJugador_porCasaHotel(int actual, ArrayList<Jugador> todos){
        informe(actual, todos);
        Jugador jug= todos.get(actual);
        jug.modificaSaldo(this.valor*jug.cantidadCasasHoteles());
    }
    
    private void informe(int actual, ArrayList<Jugador> todos){
        Jugador jug=todos.get(actual);
        Diario.getInstance().ocurreEvento("El jugador " + jug.getNombre() + " tiene la sorpresa " + this.toString());
    }
    
    
    @Override
	public String toString() {
		
                return "Sorpresa: " + this.texto;
 		//return "La Sorpresa es de tipo " + this.tipo + ", texto " + this.texto + ", valor: " + this.valor ;
	}	
    
    
}
