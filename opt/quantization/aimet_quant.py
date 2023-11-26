# from aimet_torch.quantsim import QuantizationSimModel
# from aimet_common.defs import QuantScheme

# def aimet_quant(model, bit_width=8, quant_scheme=QuantScheme.post_training_tf_enhanced):
#     """
#     Create an AIMET quantized model from a PyTorch model.
#     """
#     model.eval()
#     sim = QuantizationSimModel(model, quant_scheme=quant_scheme, bitwidth=bit_width)
#     return sim


# def export_aimet_model_to_onnx(sim, input_shape, onnx_file_path):
#     """
#     Export a quantized AIMET model to ONNX format.
#     """
#     sim.export(path=onnx_file_path, onnx_export_args={'input_shape': input_shape})