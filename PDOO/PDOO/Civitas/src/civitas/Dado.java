/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Singleton.java to edit this template
 */
package civitas;

import java.util.Random;

/**
 *
 * @author joseteo
 */
public class Dado {
    
    private Random random;
    private int ultimoResultado;
    private boolean debug;
    static final private Dado instance= new Dado();
    static final private int VALORDEBUG= 1;
    static final private int VALORRESERVADO= 6;
    
    
    private Dado() {
        this.random = new Random();
        this.ultimoResultado = 0;
        this.debug = false;
    }
    
    public static Dado getInstance() {
        return instance;
    }
    
    protected int getUltimoResultado(){
        return this.ultimoResultado;
    }
    
    protected int quienEmpieza(int n){
        return this.random.nextInt(n);
    }
    
    public void setDebug(boolean d){
        this.debug = d;
        Diario.getInstance().ocurreEvento("debug puesto a: " + d);
    }
    
    protected int tirar(){
        if(this.debug == true)
            this.ultimoResultado = 1;
        else if (this.debug == false)
            this.ultimoResultado = this.random.nextInt(6)+1;
        
        return this.ultimoResultado;
    }
        
}
