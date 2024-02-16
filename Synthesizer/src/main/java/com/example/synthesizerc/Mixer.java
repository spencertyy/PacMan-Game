package com.example.synthesizerc;

import java.util.ArrayList;

//实现一个名为 Mixer 的类，该类实现了 AudioComponent 接口，用于混合多个音频输入并生成合成的音频片段。
public class Mixer implements AudioComponent{
    private ArrayList<AudioComponent> inputs;//A list of input audio components to store用于存储输入音频组件的列表
    public Mixer() {//构造函数，初始化 inputs 列表为空
        this.inputs = new ArrayList<>();
    }

    @Override
    public AudioClip getClip() {//Used to generate mixed audio clips.
        //该方法实现了 AudioComponent 接口的方法，用于生成混合的音频片段。
        //遍历所有输入音频组件，获取各自的音频片段，并将它们合并成一个新的音频片段。
        //对于每个采样点，从每个输入音频片段中获取对应位置的样本值，并将其相加以实现混合。
        // Initialize an empty AudioClip
        AudioClip sample = new AudioClip();
        // Mix audio from all input components
        for (AudioComponent input : inputs) {
            //Go through all the input audio components,
            //and make the clip lowerVolume.and put in to the inputClip
            VolumeAdjuster lowerVolume = new VolumeAdjuster(.25);
            lowerVolume.connectInput(input);
            AudioClip inputClip = lowerVolume.getClip();
//The sample value of the corresponding position is obtained from each input audio clip and blended together.
            for (int i = 0; i < AudioClip.TOTAL_SAMPLES; i++) {
                sample.setSample(i, (inputClip.getSample(i) + sample.getSample(i)));
            }//loop all the data and put the i and the lowerVolume + the sample.getS to the sample.setS
        }
        return sample;
    }

    @Override//实现 AudioComponent 接口的方法，指示该音频组件是否有输入。在这里，总是返回 true。
    public boolean hasInput() {
        return true;
    }

    @Override//实现 AudioComponent 接口的方法，用于连接输入音频组件。在这里，将传入的音频组件存储到 inputs 列表中。
    public void connectInput(AudioComponent input) {
        inputs.add(input);//this is adding the input to inputs
    }

    public void disconnectInput(AudioComponent input) {
        inputs.remove(input);//用于断开与特定输入音频组件的连接。
    }
}//这段代码定义了一个可以将多个音频输入混合到单个音频片段中的 Mixer 类。
// 混合过程是将每个输入音频组件的音频片段按位置相加，从而合成一个新的音频片段。
