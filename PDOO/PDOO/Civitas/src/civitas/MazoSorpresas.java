/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author joseteo
 */
public class MazoSorpresas {
    private boolean baraja;
    private boolean debug;
    private int usadas;
    private ArrayList<Sorpresa> sorpresas;
    
    
    void alMazo(Sorpresa sorpresa){
        this.sorpresas.add(sorpresa);
    }
    
    private void init(){
        sorpresas = new ArrayList<>();
        baraja = false;
        usadas = 0;
    }

    MazoSorpresas(boolean debug){
        this.debug = debug;
        init();
        if (debug == true)
            Diario.getInstance().ocurreEvento("MazoSorpresas debug true");
    }
    
    MazoSorpresas(){
        init();
        debug = false;
    }
    
    Sorpresa siguiente(){
        if (baraja == false || usadas == sorpresas.size()){
            if (debug == false){
                Collections.shuffle(sorpresas);
                usadas = 0;
                baraja = true;
            }
        }
        usadas++;
        Sorpresa ultimaSorpresa = sorpresas.get(0);
        sorpresas.remove(0);
        sorpresas.add(ultimaSorpresa);
        
        return ultimaSorpresa;
    }
    
}
