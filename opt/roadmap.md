# Model Compression and Optimization

## Optimization Techniques

### Architectural Improvements

- NAS (Neural Architecture Search):
  - Use NAS to find the optimal architecture for a given task.
  
- Model specific tweaks

<!-- - **Depthwise Separable Convolutions**:
  - Replace standard convolutions with depthwise separable convolutions to
    reduce the number of parameters and computational cost.

- **Bottleneck Layers**:
  - Introduce bottleneck layers to reduce the dimensionality and computational
    load at certain points in the network.

- **Residual Connections**:
  - Add residual connections (skip connections) to help with the flow of
    gradients during training and potentially improve performance.

- **Dilated Convolutions**:
  - Use dilated convolutions in some layers to increase the receptive field
    without increasing the number of parameters. -->

### Model Pruning

### Quantization

- **Weight & Activation Quantization combo**

- **Quantization Aware Training**:
  - Train the model with quantization aware training to improve the accuracy
    of the quantized model.

### Knowledge Distillation

## Compilation and Inference Optimization

### Requirements

- **ONNX Format**:
  - Ensure the model is in ONNX (Open Neural Network Exchange) format.

### Optimizing Inference

- Platform: WebGL?

- **Use of Accelerated Libraries**?
  - Utilize libraries like TensorRT, OpenVINO, or ONNX Runtime for optimized
    inference.
