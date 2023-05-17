/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica7smm;

import java.awt.geom.AffineTransform;
import java.awt.geom.Line2D;
import java.awt.geom.PathIterator;
import java.awt.geom.Point2D;

/**
 *
 * @author joset
 */
public class TrazoLibre extends java.awt.geom.Path2D.Float {
    
    public TrazoLibre(int rule) {
        super(rule);
    }  
    
    public void setLocation(Point2D pos) {
        AffineTransform at = AffineTransform.getTranslateInstance(pos.getX(), pos.getY());
        this.transform(at);
    }
}
