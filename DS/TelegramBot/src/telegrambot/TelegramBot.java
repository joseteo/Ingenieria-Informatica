/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package telegrambot;
import java.util.Observer;
import java.util.Observable;
/**
 *
 * @author pabloxeo
 */
public class TelegramBot {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        menuComedor menu = new menuComedor();
        Observer g1 = new botTelegram(menu);
        menu.addObserver(g1);
        Ventana v = new Ventana((botTelegram)g1);
        v.setVisible(true);
        
        Thread h1 = new botTelegram(menu);
        h1.start();
    }
    
}
