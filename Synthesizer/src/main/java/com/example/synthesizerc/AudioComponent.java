package com.example.synthesizerc;

public interface AudioComponent { //like template 模版，放每个class里面需要的东西
    public AudioClip getClip();
    boolean hasInput();
    void connectInput(AudioComponent input);



}
