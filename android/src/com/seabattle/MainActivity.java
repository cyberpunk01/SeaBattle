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
import android.widget.RadioButton;

public class MainActivity extends Activity {
	
	private String TAG              = "SeaBattle";
    private final static int FREE_DECK = 1;

	private Bitmap mBackgroundLeft;
	private Bitmap mBackgroundRight;
	
    private Native mNative;
	
	private int mSideLeft, mSideRight; // Side of one tile
	
	private AIBattleField    HumanField  = null;
	private HumanBattleField AIField     = null;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
//        setContentView(R.layout.main);
//        startGame(false);
        setContentView(R.layout.start_screen);
        
        final Button button = (Button) findViewById(R.id.start_button);
        final RadioButton easyRadioButton = (RadioButton) this.findViewById(R.id.easyGame);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                startGame(easyRadioButton.isChecked());
            }
        });
    }
    
    
	private void startGame(boolean easyLevel) {
        setContentView(R.layout.main);
		
		mNative = new Native();
		mNative.Init();
		mNative.SetEasyGame(easyLevel);

        HumanField  = (AIBattleField)    this.findViewById(R.id.leftImageView);
        AIField     = (HumanBattleField) this.findViewById(R.id.rightImageView);

        HumanField.setNative(mNative);
        AIField.setNative(mNative);
        
		mSideLeft  = HumanField.getSide();
		mSideRight = AIField.getSide();
        
        mBackgroundLeft = Bitmap.createBitmap(mSideLeft, mSideLeft, Bitmap.Config.RGB_565);
        mBackgroundLeft.eraseColor(Color.BLUE);
        
        mBackgroundRight = Bitmap.createBitmap(mSideRight, mSideRight, Bitmap.Config.RGB_565);
        mBackgroundRight.eraseColor(Color.BLUE);

        HumanField.setImageBitmap(mBackgroundLeft);
        HumanField.setOnTouchListener(touchList);
        
        AIField.setImageBitmap(mBackgroundRight); 
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

			    if(event.getAction()== MotionEvent.ACTION_MOVE) {
			    }		

			    if(event.getAction()==MotionEvent.ACTION_DOWN) {
			    	
			    	int dx = (int) (x / (mSideLeft * 0.1));
			    	int dy = (int) (y / (mSideLeft * 0.1));
			    	
                    /* Human player shoots into ai field */
			    	int result = AIField.shoot(dx, dy);

                    if (result == FREE_DECK)      /// If player shoot into destroyed cell or into ship deck
	    		    	HumanField.shoot(dx, dy); /// Ai player shoots into human field

			    	AIField.postInvalidate();
                    HumanField.postInvalidate();

			    	Log.d(TAG, "X: " + Integer.toString(dx));
				    Log.d(TAG, "Y: " + Integer.toString(dy));
			    }

			return false;
		}
	};
}
