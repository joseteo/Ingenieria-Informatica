/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package practica3;

import java.awt.*;
import javax.swing.*;

/**
 *
 * @author joset
 */
public class VentanaPrincipal extends javax.swing.JFrame {

    /**
     * Creates new form VentanaPrincipal
     */
    public VentanaPrincipal() {
        initComponents();
        this.setSize(800,600);
    }

    @Override
    public void paint(Graphics g){
        super.paint(g);
        g.fillOval(this.getMousePosition().x, this.getMousePosition().y, 30, 30);
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        boton = new javax.swing.JButton();
        boton2 = new javax.swing.JButton();

        FormListener formListener = new FormListener();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addMouseListener(formListener);
        getContentPane().setLayout(new java.awt.FlowLayout());

        boton.setText("Botón");
        boton.addMouseMotionListener(formListener);
        boton.addMouseListener(formListener);
        boton.addActionListener(formListener);
        getContentPane().add(boton);

        boton2.setText("Botón2");
        boton2.addMouseListener(formListener);
        boton2.addActionListener(formListener);
        getContentPane().add(boton2);

        pack();
    }

    // Code for dispatching events from components to event handlers.

    private class FormListener implements java.awt.event.ActionListener, java.awt.event.MouseListener, java.awt.event.MouseMotionListener {
        FormListener() {}
        public void actionPerformed(java.awt.event.ActionEvent evt) {
            if (evt.getSource() == boton) {
                VentanaPrincipal.this.botonActionPerformed(evt);
            }
            else if (evt.getSource() == boton2) {
                VentanaPrincipal.this.boton2ActionPerformed(evt);
            }
        }

        public void mouseClicked(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == boton) {
                VentanaPrincipal.this.botonMouseClicked(evt);
            }
            else if (evt.getSource() == boton2) {
                VentanaPrincipal.this.boton2MouseClicked(evt);
            }
            else if (evt.getSource() == VentanaPrincipal.this) {
                VentanaPrincipal.this.formMouseClicked(evt);
            }
        }

        public void mouseEntered(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == boton) {
                VentanaPrincipal.this.botonMouseEntered(evt);
            }
        }

        public void mouseExited(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == boton) {
                VentanaPrincipal.this.botonMouseExited(evt);
            }
        }

        public void mousePressed(java.awt.event.MouseEvent evt) {
        }

        public void mouseReleased(java.awt.event.MouseEvent evt) {
        }

        public void mouseDragged(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == boton) {
                VentanaPrincipal.this.botonMouseDragged(evt);
            }
        }

        public void mouseMoved(java.awt.event.MouseEvent evt) {
        }
    }// </editor-fold>//GEN-END:initComponents

    private void botonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonActionPerformed
        // TODO add your handling code here:
        
    }//GEN-LAST:event_botonActionPerformed

    private void botonMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonMouseClicked
        // TODO add your handling code here:
        boton.setBackground(Color.red);
        String s = "Botón pulsado";
        JTextField textfield = new JTextField(" ");
        textfield.setText(s);
        add(textfield);
        setVisible(true);
        System.out.print("\n"+s+"\n");
    }//GEN-LAST:event_botonMouseClicked

    private void botonMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonMouseEntered
        // TODO add your handling code here:
        boton.setBackground(Color.blue);
    }//GEN-LAST:event_botonMouseEntered

    private void botonMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonMouseExited
        // TODO add your handling code here:
        boton.setBackground(Color.green);
    }//GEN-LAST:event_botonMouseExited

    private void botonMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_botonMouseDragged
        // TODO add your handling code here:
        boton.setLocation(evt.getPoint());
    }//GEN-LAST:event_botonMouseDragged

    private void boton2MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_boton2MouseClicked
        // TODO add your handling code here:
        boton2.setBackground(Color.LIGHT_GRAY);
    }//GEN-LAST:event_boton2MouseClicked

    private void boton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_boton2ActionPerformed
        // TODO add your handling code here:
        boton2.setBackground(Color.red);
    }//GEN-LAST:event_boton2ActionPerformed

    private void formMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_formMouseClicked
        // TODO add your handling code here:
        //evt.getPoint();
        this.repaint();
    }//GEN-LAST:event_formMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VentanaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VentanaPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton boton;
    private javax.swing.JButton boton2;
    // End of variables declaration//GEN-END:variables
}
