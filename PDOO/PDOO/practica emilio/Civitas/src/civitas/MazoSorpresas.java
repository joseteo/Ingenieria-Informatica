/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author emilio
 */
public class MazoSorpresas {
    //Relacciones
    private ArrayList<Sorpresa> sorpresas;
    
    //Atributos de instancia
    private boolean barajada;
    private int usadas;
    private boolean debug=false;
    private int ultimaSorpresa;
    
    //metodo privado
    private void init(){
        this.sorpresas = new ArrayList<Sorpresa>();
        this.barajada=false;
        this.usadas=0;
    }
    //visibilidad de paquete
     MazoSorpresas(boolean modoDebug){
        this.debug=modoDebug;
        init();
        if(this.debug){
            Diario.getInstance().ocurreEvento("Se ha activado el modo DEBUG");
        }
    }
    
    MazoSorpresas(){
        init();
        this.debug=false;
    }
           
    void alMazo(Sorpresa sorpresa){
        if(!barajada){
            this.sorpresas.add(sorpresa);
        }
    }
    
     Sorpresa siguiente(){
        Sorpresa s;
        if(!barajada || usadas==sorpresas.size()){
            if(!this.debug){
                //desactivar shuffle para forzar las sorpresas
                //Collections.shuffle(sorpresas);
                this.usadas=0;
                this.barajada=true; 
            }
        }
        s=sorpresas.get(0);
        this.usadas+=1;
        sorpresas.remove(0);
        sorpresas.add(s);
        return s;
        
        
        
    }
            
            
}
