package com.example.helloandroid;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    final String MsTag= "onCreate";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
    }
public void handleButton(View view){
        TextView text = findViewById(R.id.textView);
        text.setText("Button was passed...");


        Log.d(MsTag,"Button was passed...");
}
}