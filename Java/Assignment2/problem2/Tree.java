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

class Tree extends JFrame
{

//counting frequency of every token in the string//

	public static int[] freqCount(String S){

		int[] f=new int[10000];
		for(int i=0;i<S.length();i++){

			f[S.charAt(i)]++;

		}

		return f;
	}


//building the huffman tree from a String S//


	public static Node buildTree(String S)
	{
		PriorityQueue<Node>queue=new PriorityQueue<Node>();
		int[]f=new int[10000];
		f=freqCount(S);
		for(char i=0;i<f.length;i++){
			if(f[i]>0){
				Node n=new Node(i,f[i],null,null,0);
				queue.add(n);
			}
		}
		int c=1;
		while(queue.size()>1){
			Node l1=queue.poll();
			l1.setcount(c);
			c++;
			Node l2=queue.poll();
			l2.setcount(c);
			c++;
			Node parent=new Node('\0',l1.freq+l2.freq,l1,l2,0);
			queue.add(parent);
		}
		return queue.poll();
	}
}