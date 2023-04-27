/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telegrambot;
import java.util.Observable;

/**
 *
 * @author pabloxeo
 */
public class menuComedor extends Observable{
    private String primer_plato;
    private String segundo_plato;
    private String postre;
    private boolean menu_nuevo = false;

    @Override
    public String toString() {
        return "Primer plato: " + primer_plato + ", Segundo plato: " + segundo_plato + ", Postre: " + postre; 
        
    }
    
    public String getMenu(){
        return "Primer plato: " + primer_plato + ", Segundo plato: " + segundo_plato + ", Postre: " + postre;
    }
    
    public void setmenu_Nuevo(String primer_plato, String segundo_plato, String postre) {
        this.primer_plato = primer_plato;
        this.segundo_plato = segundo_plato;
        this.postre = postre;
        menu_nuevo = true;
    }

    public void setmenu_Bot(String primer_plato, String segundo_plato, String postre) {
        setmenu_Nuevo(primer_plato, segundo_plato, postre);
        setChanged();
        notifyObservers();
    }
    
    boolean menu_es_nuevo(){
        return menu_nuevo;
    }
    
}
