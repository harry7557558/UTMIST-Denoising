import torch
import torch.quantization

def torch_quant(model):
    """
    Quantize a PyTorch model using post-training static quantization.
    """
    model.eval()
    model.qconfig = torch.quantization.get_default_qconfig('fbgemm')
    torch.quantization.prepare(model, inplace=True)

    # Dummy calibration with random data
    sample_input = torch.randn(1, 3, 224, 224)
    model(sample_input)

    torch.quantization.convert(model, inplace=True)
    return model

def torch_to_onnx(model, input_shape, onnx_file_path):
    """
    Export a quantized PyTorch model to ONNX format.
    """
    model.eval()
    sample_input = torch.randn(*input_shape)
    torch.onnx.export(model, sample_input, onnx_file_path, export_params=True)
