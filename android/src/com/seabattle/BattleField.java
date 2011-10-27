package com.seabattle;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.util.Log;
import android.widget.ImageView;

public class BattleField extends ImageView{
	
	protected int[][] mMatrix = {{0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
							     {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
								 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},};
	
	private Bitmap mSea, mShip, mBroken, mMiss;

	public BattleField(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		initBitmaps();
		// TODO Auto-generated constructor stub
	}

	public BattleField(Context context, AttributeSet attrs) {
		super(context, attrs);
		initBitmaps();
		// TODO Auto-generated constructor stub
	}

	public BattleField(Context context) {
		super(context);
		initBitmaps();
		// TODO Auto-generated constructor stub
		

	}
	
	private void initBitmaps()
	{
		mSea = Bitmap.createBitmap(48, 48, Bitmap.Config.RGB_565);
		mSea.eraseColor(Color.BLUE);
		
		mShip = Bitmap.createBitmap(48, 48, Bitmap.Config.RGB_565);
		mShip.eraseColor(Color.GRAY);
		
		mBroken = Bitmap.createBitmap(48, 48, Bitmap.Config.RGB_565);
		mBroken.eraseColor(Color.RED);
		
		mMiss = Bitmap.createBitmap(48, 48, Bitmap.Config.RGB_565);
		mMiss.eraseColor(Color.BLACK);
		
		
	}

	@Override
	protected void onDraw(Canvas canvas) {
		// TODO Auto-generated method stub
		super.onDraw(canvas);
		Log.i("SeaBattle", "onDraw");
		for (int i = 0; i < 9; i+=1)
			for (int j = 0; j < 9; j+=1)
			{
				if (mMatrix[i][j] == 0)
				{
			//		Log.i("SeaBattle", "SeaTile");
					canvas.drawBitmap(mSea, i * 48, j * 48, new Paint());	
				}
				else if (mMatrix[i][j] == 1)
				{
			//		Log.i("SeaBattle", "MissTile");
					canvas.drawBitmap(mShip, i * 48, j * 48, new Paint());
				}
				else if (mMatrix[i][j] == 2)
				{
			//		Log.i("SeaBattle", "MissTile");
					canvas.drawBitmap(mMiss, i * 48, j * 48, new Paint());
				}
				else if (mMatrix[i][j] == 3)
				{
			//		Log.i("SeaBattle", "BrokenTile");
					canvas.drawBitmap(mBroken, i * 48, j * 48, new Paint());
				}
			}
	}
	
	public void setMatrix(int x, int y, int param)
	{
		Log.i("SeaBattle", "Matrix not changed:" + Integer.toString(mMatrix[x][y]));
		mMatrix[x][y] = param;
		Log.i("SeaBattle", "Matrix changed:" + Integer.toString(mMatrix[x][y]));
	}
	
	

}
