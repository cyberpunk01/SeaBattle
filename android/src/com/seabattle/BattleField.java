package com.seabattle;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.view.Display;
import android.view.WindowManager;
import android.widget.ImageView;

public class BattleField extends ImageView{
	
	protected int[][] mMatrix;

	
	private Bitmap mSea, mShip, mBroken, mMiss;
	private Native mNative;
	
	private int mSide;

	public BattleField(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		initBitmaps(context);
		// TODO Auto-generated constructor stub
	}

	public BattleField(Context context, AttributeSet attrs) {
		super(context, attrs);
		initBitmaps(context);
		// TODO Auto-generated constructor stub
	}

	public BattleField(Context context) {
		super(context);
		initBitmaps(context);
		// TODO Auto-generated constructor stub
		

	}
	
	private void initBitmaps(Context context)
	{
		Display display = ((WindowManager) context.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		mSide = (int) ((display.getHeight() - 30) * 0.1);
		
		mNative = new Native();
		mNative.Init();
		
		mSea = Bitmap.createBitmap(mSide, mSide, Bitmap.Config.RGB_565);
		mSea.eraseColor(Color.BLUE);
		
		mShip = Bitmap.createBitmap(mSide, mSide, Bitmap.Config.RGB_565);
		mShip.eraseColor(Color.GRAY);
		
		mBroken = Bitmap.createBitmap(mSide, mSide, Bitmap.Config.RGB_565);
		mBroken.eraseColor(Color.RED);
		
		mMiss = Bitmap.createBitmap(mSide, mSide, Bitmap.Config.RGB_565);
		mMiss.eraseColor(Color.BLACK);
		
		mMatrix = new int[10][10];
		
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				mMatrix[i][j] = 1;
			}
	}
	
	private void updateMatrix() {
		int[] arr = new int[100];
		mNative.GetField(arr);
		
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				mMatrix[i][j] = arr[10*i + j];

	}

	@Override
	protected void onDraw(Canvas canvas) {
		// TODO Auto-generated method stub
		super.onDraw(canvas);
		updateMatrix();
		Log.i("SeaBattle", "onDraw");
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				if (mMatrix[i][j] == 1)
				{
			//		Log.i("SeaBattle", "SeaTile");
					canvas.drawBitmap(mSea, i * mSide, j * mSide, new Paint());	
				}
				else if (mMatrix[i][j] == 2)
				{
			//		Log.i("SeaBattle", "MissTile");
					canvas.drawBitmap(mShip, i * mSide, j * mSide, new Paint());
				}
				else if (mMatrix[i][j] == 4)
				{
			//		Log.i("SeaBattle", "BrokenTile");
					canvas.drawBitmap(mBroken, i * mSide, j * mSide, new Paint());
				}
				else if (mMatrix[i][j] == 8)
				{
			//		Log.i("SeaBattle", "MissTile");
					canvas.drawBitmap(mMiss, i * mSide, j * mSide, new Paint());
				}
			}
	}
	
	public void shoot(int x, int y)
	{
		Log.i("SeaBattle", "Matrix not changed:" + Integer.toString(mMatrix[x][y]));
		mMatrix[x][y] = mNative.Shoot(x, y);
		updateMatrix();
		Log.i("SeaBattle", "Matrix changed:" + Integer.toString(mMatrix[x][y]));
	}
	
	public int getSide() {
		
		return mSide;
	}
	
	

}
