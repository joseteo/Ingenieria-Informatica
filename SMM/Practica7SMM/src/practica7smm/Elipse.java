/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica7smm;

import java.awt.geom.Rectangle2D;

/**
 *
 * @author joset
 */
public class Elipse extends java.awt.geom.Ellipse2D.Double {

    public Elipse(double x, double y, double w, double h){
        super(x,y,w,h);
    }
    
    
    @Override
    public void setFrame(double x, double y, double w, double h){
        super.setFrame(x, y, w, h);
    }
}
