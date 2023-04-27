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
public class botTelegram extends Thread implements Observer{
    menuComedor menu = new menuComedor();
    String menuts = "";
    private boolean estadoBot = false;
    
    public botTelegram(Observable menu_o){
        menu = (menuComedor) menu_o;
        estadoBot = true;
        
    }
    
    public boolean getEstadoBot(){
        return estadoBot;
    }
    
    public void publicarMenu(){
        System.out.println(menuts);
    }
    
    public void cambiarMenu(String primer_plato, String segundo_plato, String postre){
        menu.setmenu_Bot(primer_plato, segundo_plato, postre);
    }
    
    @Override
    public void update(Observable menu_ob, Object arg)
    {
      menu = (menuComedor) menu_ob;
      menuts = menu.getMenu();
    }
    
    public void run(){
        while(true){
            update(menu, null);
            try {
                sleep(2000);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }    
    
}
