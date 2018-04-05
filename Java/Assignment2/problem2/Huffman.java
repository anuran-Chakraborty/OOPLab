import java.io.*;
import javax.swing.*;
import java.awt.event.*;   
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;


class Huffman extends JFrame 
{

	JLabel l1;
	JTextField t1;
	JButton b1,b2;

//Screen for taking the string input// 
	
	public Huffman()
	{
		
		super("STRING INPUT WINDOW");	
		setLayout(new FlowLayout());
		setSize(1000,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setVisible(true);
		build_component();
	}

	public void  build_component(){
		
		l1 = new JLabel("ENTER A STRING");
		l1.setFont(new Font("Serif", Font.BOLD, 25));
		t1 = new  JTextField(50);
		b1 = new JButton("ENTER");
		b1.setSize(50,50);
		b1.setLocation(95,45);
		b2 = new JButton("EXIT");
		b2.setSize(50,50);
		b2.setLocation(105,45);
		add(l1);	
		add(t1);
		add(b1);
		add(b2);
		b1.addActionListener(new MyListener());
		b2.addActionListener(new MyListener());
	}

	private class MyListener implements ActionListener
	{

		public void actionPerformed(ActionEvent e){

			if(e.getSource()==b2)
				System.exit(0);
			else{
				String s = t1.getText();
				Tree t = new Tree();

				NewWindow NW= new NewWindow(t.buildTree(s));
			}
		}
	}
}
