package com.example.synthesizerc;

import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.RadialGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Circle;

import java.util.ArrayList;

public class MixerWidget extends AudioComponentWidgetBase {

    public static Circle inputMixerCirle;



    public MixerWidget(AudioComponent audioComponent, AnchorPane parent, String label) {

        //final shoe here is ac1Mixer.getClip()
        super(audioComponent, parent, label);
    }

    public void addInputCircle(){
        inputMixerCirle= new Circle(10);
        RadialGradient gradient1 = new RadialGradient(0,
                .1,
                0.5,
                0.5,
                2,
                true,
                javafx.scene.paint.CycleMethod.NO_CYCLE,
                new Stop(0, Color.WHITE),
                new Stop(0.5, Color.BLUE));
        inputMixerCirle.setFill(gradient1);
//        input.setOnMousePressed(e->startConn(e,input));
//        input.setOnMouseDragged(e->moveConn(e,input));
//        input.setOnMouseReleased(e->endConn(e,input));
        leftside.getChildren().add(inputMixerCirle);

    }


}


