/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica7smm;

import java.awt.Point;
import java.awt.geom.Point2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author joset
 */
public class Linea2D extends java.awt.geom.Line2D.Double{

    public Linea2D(Point2D p1, Point2D p2){
        super(p1, p2);
    }
    
    public boolean isNear(Point2D p1){
        // Caso p1=p2 (punto)
        if(this.getP1().equals(this.getP2())) 
            return this.getP1().distance(p1)<=4.0;
        // Caso p1!=p2
        return this.ptLineDist(p1)<=4.0;
    }
    
    @Override
    public boolean contains(Point2D p1){
        return isNear(p1);
    }

    public void setLocation(Point2D p1) {
        double NuevoX = p1.getX() - this.getX1();
        double NuevoY = p1.getY() - this.getY1();
        Point2D NuevoP = new Point2D.Double(
                this.getX2() + NuevoX,
                this.getY2() + NuevoY);
        
        this.setLine(p1, NuevoP);
    }
}
