import time
import functools

def profile_performance(func):
    """
    A decorator for profiling the inference performance in terms of latency.
    Optional: Extend this to profile accuracy and memory usage.
    """
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        latency = end_time - start_time
        print(f"Inference Latency: {latency * 1000:.2f} ms")
        return result
    return wrapper
