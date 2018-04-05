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

class  Node implements Comparable<Node>
{

	public char ch;
	public  int freq;
	public Node left,right;
	public int count;

	Node(char ch,int freq,Node left,Node right,int count)
	{
		this.ch=ch;
		this.freq=freq;
		this.left=left;
		this.right=right;
		this.count=count;
	}

	private boolean isLeaf()
	{
		assert ((left == null) && (right == null)) || ((left != null) && (right != null));
		return (left == null) && (right == null);
	}
	public int compareTo(Node a)
	{

		if(freq<a.freq)
			return -1;
		else if(freq>a.freq)
			return 1;
		else
			return 0;
	}
	
	public void setcount(int c){
		this.count=c;
	}
}
