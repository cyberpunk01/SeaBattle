package com.seabattle;


import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.os.Bundle;
import android.util.Log;
import android.view.Display;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;


public class MainActivity extends Activity {
	
	
	private String TAG = "SeaBattle";
	private Bitmap background;
	
	private int mSide; // Side of one tile
	
	private BattleField mLeftField = null;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.start_screen);
        
        final Button button = (Button) findViewById(R.id.start_button);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                startGame(true);
            }
        });
    }
    
    
	private void startGame(Boolean easyLevel) {
		//TODO: set game level
		setContentView(R.layout.main);
		
		mLeftField = new BattleField(getApplicationContext());
		
		mSide = mLeftField.getSide() * 10;

        
        mLeftField = (BattleField) this.findViewById(R.id.leftImageView);
        background = Bitmap.createBitmap(mSide, mSide, Bitmap.Config.RGB_565);
        background.eraseColor(Color.BLUE);

        mLeftField.setImageBitmap(background);
        mLeftField.setOnTouchListener(touchList);
    }
    
	
    View.OnTouchListener touchList = new View.OnTouchListener() {
		public boolean onTouch(View v, MotionEvent event) {
			Log.i(TAG,"Touch");
			
				final int x = (int)event.getX();
				final int y = (int)event.getY();
				Log.d(TAG,Integer.toString(x));
				Log.d(TAG,Integer.toString(y));
				
				if(event.getAction()==MotionEvent.ACTION_UP) {

			    }
			    if(event.getAction()==MotionEvent.ACTION_DOWN) {
			    	
			    	int dx = (int) (x / (mSide * 0.1));
			    	int dy = (int) (y / (mSide * 0.1));
			    	
			    	mLeftField.shoot(dx, dy);
			    	mLeftField.postInvalidate();

			    	
					Log.d(TAG, "X: " + Integer.toString(dx));
					Log.d(TAG, "Y: " + Integer.toString(dy));
			    }
			    if(event.getAction()== MotionEvent.ACTION_MOVE) {

			    }		
			return false;
		}
	};
}